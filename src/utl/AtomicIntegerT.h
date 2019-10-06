//
// Created by devinchang on 2019/9/16.
//

#ifndef INC_315SERVER_ATOMICINTEGERT_H
#define INC_315SERVER_ATOMICINTEGERT_H

#include <stdint.h>


/* gcc提供了__sync_*系列的内嵌函数,提供用于对数字或布尔型变量的原子性操作
 *
 * */

// 原子生成器
template <typename T>
class AtomicIntegerT {
public:
    AtomicIntegerT() : value_(0){}

    // type __sync_val_compare_and_swap (type *ptr, type oldval type newval, ...)
    // 比较*ptr与oldval的值,如果相等,则将newval更新到*ptr,并返回操作之前的*ptr的值
    T get() const { return __sync_val_compare_swap(const_cast<volatile T*> (&value_), 0, 0);}

    // 将x加到value上,并更新value为新加后的值
    T getAndAdd(T x){ return __sync_fetch_and_add(&value_ , x); }

    T addAndGet(T x){ return getAndAdd(x) + x; }

    T incrementAndGet() { return addAndGet(1); }

    void add(T x){ getAndAdd(x); }

    void increment(){ incrementAndGet();}

    void decrement() { getAndAdd(-1);}

    // type __sync_lock_test_and_set (type *ptr, type value, ...)
    // 将value写入*ptr,对*ptr加锁,返回操作之前*ptr的值
    T getAndSet(T newVal){ return __sync_lock_test_and_set(&value_, newVal);}


private:
    volatile T value_;
};

typedef AtomicIntegerT<int32_t> AtomicInt32;
typedef AtomicIntegerT<int64_t> AtomicInt64;

#endif //INC_315SERVER_ATOMICINTEGERT_H
