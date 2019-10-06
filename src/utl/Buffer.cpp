//
// Created by devinchang on 2019/9/11.
//

#include "Buffer.h"
#include <errno.h>
#include <memory>
#include <sys/uio.h>
#include "Util.h"

/* 为了提高从磁盘读取数据到内存的效率,引入了IO向量机制
 * struct iovec{
 *     void *iov_base;
 *     size_t iov_len;
 * }
 * 定以了一个向量元素,iov_base指向一个缓冲区,用于存放readv和writev所接收或是发送的数据.
 * iov_len则分别确认了接收的最大长度以及实际写入的长度.
 *
 * readv和writev作用类似与read和write,不同的是readv和writev在一次执行过程中可以原子地作用于
 * 多个缓冲区,这些缓冲区常常是非连续的.
 * */


ssize_t Buffer::readFd(int fd, int *savedErrno) {
    char extrabuf[65536];
    struct iovec vec[2];
    const size_t writable = writableBytes();
    vec[0].iov_base = begin() + writerIndex_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof(extrabuf);
    const ssize_t n = readv(fd, vec, 2);
    if(n < 0){
        *savedErrno = errno;
    }
    else if(util::implicit_cast<size_t>(n) <= writable){
        writerIndex_ += n;
    }
    else{
        writerIndex_ = buffer_.size();
        append(extrabuf, n - writable);
    }
    return n;
}
