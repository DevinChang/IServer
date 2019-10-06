//
// Created by devinchang on 2019/9/9.
//

#ifndef INC_315SERVER_UTIL_H
#define INC_315SERVER_UTIL_H

#include <memory>
#include <errno.h>
#include <string.h>
#include <assert.h>
//#include "Buffer.h"
#include <string>
#include <iostream>

#include <iosfwd>

//#define CHECK_NOTNULL(val) CheckNotNull(__FILE__, __LINE__, "'"#val"'Must be non NUll", (val))
//
//template <typename T>
//T *CheckNotNull(const char *file, int line, const char *names, T *ptr){
//    if(ptr == NULL)
//        std::cout << "error: " << names;
//    return ptr;
//}

namespace util{
    template <typename T>
    inline T *get_pointer(const std::shared_ptr<T> &ptr){
        // 智能指针的get函数返回一个内置指针,指向智能指针管理的对象. 通常用于不能使用智能指针的代码
        // 传递一个内置指针. 注意：使用get返回的指针代码不能delete此指针
        return ptr.get();
    }

    template <typename T>
    inline T *get_pointer(const std::unique_ptr<T> &ptr){
        return ptr.get();
    }

    template<typename To, typename From>
    inline To implicit_cast(From const &f){
        return f;
    }

    const char *strerror_tl(int savedErrno);
}

namespace log{
    const int kSmallBuffer = 4000;
    const int kLargeBuffer = 4000 * 1000;

    template<int SIZE>
    class FixedBuffer{
    public:
        FixedBuffer(): cur_(data_){
            setCookie(cookieStart);
        }

        ~FixedBuffer(){
            setCookie(cookieEnd);
        }

        void append(const char *buf, size_t len){
            if(util::implicit_cast<size_t>(avail()) > len){
                memcpy(cur_, buf, len);
                cur_ += len;
            }
        }

        const char *data() const {return data_; }
        int length() const { return static_cast<int>(cur_ - data_); }

        char *current() { return cur_; }
        int avail() const { return static_cast<int>(end() - cur_); }
        void add(size_t len) { cur_ + len; }

        void reset() { cur_ = data_; }
        void bzero() { ::bzero(data_, sizeof(data_)); }

        const char *debugString();
        void setCookie(void (*cookie)()){ cookie_ = cookie; }

        std::string toString() const { return std::string(data_, length()); }
        std::string asString() const { return std::string(data_, length()); }

    private:
        const char *end() const { return data_ + sizeof(data_);}

        static void cookieStart();
        static void cookieEnd();

        void (*cookie_)();

        char data_[SIZE];
        char *cur_;
    };

    // 用于类在编译期间推导出string的长度
    class T{
    public:
        T(const char *str, int len): str_(str), len_(len){
            assert(strlen(str) == len);
        }

        const char *str_;
        const size_t len_;
    };


    class LogStream{
        typedef LogStream self;
    public:
        typedef FixedBuffer<kSmallBuffer> Buffer;

        self &operator <<(bool v){
            buffer_.append(v ? "1" : "0" , 1);
            return *this;
        }

        self &operator <<(short);
        self &operator <<(unsigned short);
        self &operator <<(int);
        self &operator <<(unsigned int);
        self &operator <<(long);
        self &operator <<(unsigned long);
        self &operator <<(long long);
        self &operator <<(unsigned long long);

        self &operator <<(const void *);

        self &operator <<(double);

        self &operator <<(float v){
            *this << static_cast<double>(v);
            return *this;
        }

        self &operator <<(char v){
            buffer_.append(&v, 1);
            return *this;
        }

        self &operator <<(const char *v){
            buffer_.append(v, strlen(v));
            return *this;
        }

        self &operator <<(const T& v){
            buffer_.append(v.str_, v.len_);
            return *this;
        }

        self &operator <<(const std::string &v){
            buffer_.append(v.c_str(), v.size());
            return *this;
        }

        void append(const char *data, int len){ buffer_.append(data, len); }
        const Buffer &buffer() const { return buffer_; }
        void resetBuffer() { buffer_.reset(); }
    private:
        void staticCheck();

        template <typename T>
        void formatInteger(T);

        Buffer buffer_;

        static const int kMaxNumericSize = 32;
    };

    class Fmt{
    public:
        template<typename T>
        Fmt(const char *fmt, T val);

        const char *data() const { return buf_; }
        int length() const { return length_; }
    private:
        char buf_[32];
        int length_;
    };

    inline LogStream &operator <<(LogStream &s, const Fmt &fmt){
        s.append(fmt.data(), fmt.length());
        return s;
    }
}

namespace strpiece{

    class StringArg{
    public:
        StringArg(const char *str): str_(str){}

        StringArg(const std::string &str): str_(str.c_str()){}

        const char *c_str() const { return str_; }

    private:
        const char *str_;
    };


    class StringPiece{
    public:
        StringPiece() : ptr_(NULL), length_(0){}
        StringPiece(const char *str): ptr_(str), length_(static_cast<int>(strlen(ptr_))){}
        StringPiece(const unsigned char *str): ptr_(reinterpret_cast<const char *>(str)), length_(static_cast<int>(strlen(ptr_))){}
        StringPiece(const std::string &str): ptr_(str.data()), length_(static_cast<int>(str.size())){}
        StringPiece(const char *offset, int len): ptr_(offset), length_(len){}

        const char *data() const { return ptr_; }
        int size() const { return length_; }
        bool empty() const { return length_ == 0; }
        const char *begin() const { return ptr_; }
        const char *end() const { return ptr_ + length_; }
        void clear() { ptr_ = NULL; length_ = 0; }
        void set(const char *buffer, int len){ ptr_ = buffer; length_ = len; }
        void set(const char *str){ ptr_ = str; length_ = static_cast<int>(strlen(str));}
        void remove_prefix(int n){ ptr_ += n; length_ -= n; }
        void remove_suffix(int n){ length_ -= n; }

        char operator[](int i) const { return ptr_[i]; }
        bool operator == (const StringPiece &x) const { return ((length_ == x.length_) && (memcmp(ptr_, x.ptr_, length_) == 0)); }
        bool operator != (const StringPiece &x) const { return !(*this == x); }

        #define STRINGPIECE_BINARY_PREDICATE(cmp, auxcmp) \
          bool operator cmp(const StringPiece &x) const { \
            int r = memcmp(ptr_, x.ptr_, length_ < x.length_ ? length_ : x.length_); \
            return ((r auxcmp 0)  || ((r == 0) && (length_ cmp x.length_))); \
         }
         STRINGPIECE_BINARY_PREDICATE(<, <);
         STRINGPIECE_BINARY_PREDICATE(<=, <);
         STRINGPIECE_BINARY_PREDICATE(>=, >);
         STRINGPIECE_BINARY_PREDICATE(>, >);
        #undef STRINGPIECE_BINARY_PREDICATE
        int compare(const StringPiece &x) const {
            int r = memcmp(ptr_, x.ptr_, length_ < x.length_ ? length_ : x.length_);
            if(r == 0){
                if(length_ < x.length_)
                    r = -1;
                else if(length_ > x.length_)
                    r = +1;
            }
            return r;
        }

        std::string as_string() const{ return std::string(data(), size()); }

        void CopyToString(std::string *target) const { target->assign(ptr_, length_); }

        bool starts_with(const StringPiece &x) const { return ((length_ >= x.length_) && (memcmp(ptr_, x.ptr_, x.length_) == 0)); }
    private:
        const char *ptr_;
        int length_;
    };
}

#endif //INC_315SERVER_UTIL_H



