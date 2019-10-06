//
// Created by devinchang on 2019/9/11.
//

#ifndef INC_315SERVER_BUFFER_H
#define INC_315SERVER_BUFFER_H

#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <functional>
#include "Util.h"


class Buffer {
public:
    static const size_t kCheapPrepend = 8;
    static const size_t kInitialSize = 1024;
public:
    Buffer() : buffer_(kCheapPrepend + kInitialSize),
               readerIndex_(kCheapPrepend),
               writerIndex_(kCheapPrepend){
        assert(readableBytes() == 0);
        assert(writableBytes() == kInitialSize);
        assert(prependableBytes() == kCheapPrepend);
    }

    void swap(Buffer &rhs){
        buffer_.swap(rhs.buffer_);
        std::swap(readerIndex_, rhs.readerIndex_);
        std::swap(writerIndex_, rhs.writerIndex_);
    }

    size_t readableBytes() const { return writerIndex_ - readerIndex_; }
    size_t writableBytes() const { return buffer_.size() - writerIndex_; }
    size_t prependableBytes() const { return readerIndex_; }

    const char *peek() const{ return begin() + readerIndex_; }

    void retrieve(size_t len){
        assert(len <= readableBytes());
        readerIndex_ += len;
    }

    void retrieveUntil(const char *end){
        assert(peek() <= end);
        assert(end <= beginWrite());
        retrieve(end-peek());
    }

    void retrieveAll(){
        readerIndex_ = kCheapPrepend;
        writerIndex_ = kCheapPrepend;
    }

    std::string retrieveAsString(){
        return retrieveAsString(readableBytes());
    }

    std::string retrieveAsString(size_t len){
        assert(len <= readableBytes());
        std::string result(peek(), len);
        retrieve(len);
        return result;
    }

    void append(const std::string &str){
        append(str.data(), str.length());
    }

    void append(const char *data, size_t len){
        ensureWritableBytes(len);
        std::copy(data, data+len, beginWrite());
        hasWritten(len);
    }

    void append(const void *data, size_t len){
        append(static_cast<const char *>(data), len);
    }

    // 10/6 new add
    void append(strpiece::StringPiece &str){
        append(str.data(), str.size());
    }

    void ensureWritableBytes(size_t len){
        if(writableBytes() < len){
            makeSpace(len);
        }
        assert(writableBytes() >= len);
    }

    char *beginWrite(){ return begin() + writerIndex_; }

    const char *beginWrite() const { return begin() + writerIndex_; }

    void hasWritten(size_t len){ writerIndex_ += len; }

    void prepend(const void *data, size_t len){
        assert(len <= prependableBytes());
        readerIndex_ -= len;
        const char *d = static_cast<const char*>(data);
        std::copy(d, d+len, begin() + readerIndex_);
    }

    void shrink(size_t reserve){
        std::vector<char> buf(kCheapPrepend + readableBytes() + reserve);
        std::copy(peek(), peek() + readableBytes(), buf.begin() + kCheapPrepend);
        buf.swap(buffer_);
    }

    ssize_t readFd(int fd, int *savedErrno);

    // 10/6 new add
    std::string retrieveAllAsString(){
        return retrieveAsString(readableBytes());
    }

    strpiece::StringPiece toStringPiece() const{
        return strpiece::StringPiece(peek(), static_cast<int>(readableBytes()));
    }

private:
    char *begin() { return &*buffer_.begin(); }

    const char *begin() const { return &*buffer_.begin(); }

    void makeSpace(size_t len){
        if(writableBytes() + prependableBytes() < len + kCheapPrepend){
            buffer_.resize(writerIndex_ + len);
        }
        else{
            assert(kCheapPrepend < readerIndex_);
            size_t readable = readableBytes();
            std::copy(begin() + readerIndex_, begin()+writerIndex_, begin() + kCheapPrepend);
            readerIndex_ = kCheapPrepend;
            writerIndex_ = readerIndex_ + readable;
            assert(readable == readableBytes());
        }
    }
private:
    std::vector<char> buffer_;
    size_t readerIndex_;
    size_t writerIndex_;
};


#endif //INC_315SERVER_BUFFER_H