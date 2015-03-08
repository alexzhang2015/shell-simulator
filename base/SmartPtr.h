/* Shell Simulator
 * 2010.08.21 by alex
 */


/*
 * Copyright 2009, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


// Yet another implementation of a basic, intrusive reference-counting system.

#ifndef BASE_SMART_PTR_H_
#define BASE_SMART_PTR_H_
#pragma once 

#include "BasicType.h"

// The intrusive part of the reference counting mechanism.  All objects to
// be used within the reference-counting system must inherit from RefCounted.
// The class contains the reference count.
class RefCounted {
  template <class C>
  friend class SmartPointer;
 protected:
  RefCounted() : reference_count_(0) {
  }

  // Call when a new reference is made to the object.
  void AddRef() const {
    ++reference_count_;
  }

  // Call when a reference to the object is no longer needed.
  int Release() const {
    return --reference_count_;
  }

 private:
  mutable int reference_count_;
  DISALLOW_COPY_AND_ASSIGN(RefCounted);
};


// Template wrapper class that controls the lifetime of heap-constructed
// objects.
template <class C>
class SmartPointer {
 public:
  typedef C* Pointer;
  typedef C& Reference;
  typedef C  ClassType;

  // SmartPointer objects initialize to NULL on construction.
  SmartPointer() : data_(NULL) {
  }

  // This copy constructor is not marked explicit on purpose, so that
  // we can copy smart pointers implicitly.
  SmartPointer(const SmartPointer<C>& pointer)  // NOLINT
      : data_(pointer.Get()) {
    AddRef();
  }

  explicit SmartPointer(Pointer data) : data_(data) {
    AddRef();
  }

  ~SmartPointer() {
    Release();
  }

  // SmartPointer<InstanceCount> smart_ptr1(new InstanceCount());
  // SmartPointer<InstanceCount> smart_ptr2(smart_ptr1);
  // SmartPointer<InstanceCount> smart_ptr1 = smart_ptr2;
  SmartPointer<C>& operator=(const SmartPointer<C>& rhs);

  // SmartPointer<InstanceCount> smart_ptr1 = new InstanceCount;
  SmartPointer<C>& operator=(const Pointer data);

  // Operators to return a reference and pointer to the data, respectively.
  // Note that the constness of the operators obeys normal C++ pointer
  // semantics:  If the pointer is const, the data is not const.	
  Reference operator*() const {
    return *data_;
  }
  Pointer operator->() const {
    return data_;
  }

  // Casting opertor needed by the plug-in generator code.
  // TODO: Remove this method so that all conversions between smart-
  // pointers and raw-pointers are explicit.
  operator Pointer() const {
    return data_;
  }

  Pointer Get() const {
    return data_;
  }

  bool IsNull() const {
    return data_ == NULL;
  }

  void Reset() {
    *this = SmartPointer<C>(NULL);
  }

 private:
  // Helper function to conditionally add a reference to the pointed-to-data.
  void AddRef() {
    if (data_) {
      data_->AddRef();
    }
  }

  // Helper function to decrement the reference count of the pointed-to-data.
  // If the reference count is zero after the decrement, then the object is
  // deleted, and the pointer assigned to NULL.
  void Release();

  Pointer data_;
};

// Provide a convenience equality test operator on SmartPointer objects.
template <class C>
inline bool operator==(const SmartPointer<C>& lhs, const SmartPointer<C>& rhs) {
  return lhs.Get() == rhs.Get();
}

template <class C>
inline SmartPointer<C>& SmartPointer<C>::operator=(const SmartPointer<C>& rhs) {
  if (this == &rhs) {
    return *this;
  }

  Release();
  data_ = rhs.data_;
  AddRef();
  return *this;
}

template <class C>
inline SmartPointer<C>& SmartPointer<C>::operator=(const Pointer data) {

  Release();
  data_ = data;
  AddRef();
  return *this;
}

template <class C>
void SmartPointer<C>::Release() {
  if (data_) {
    if (data_->Release() == 0) {
      delete data_;
    }
    data_ = NULL;
  }
}


#endif  // BASE_SMART_PTR_H_

/*
 * Test code. by alex.
class InstanceCount : public RefCounted {
 public:
  // Use construction & destruction to inc/dec a static instance counter.
  InstanceCount() { ++instance_count_; }
  ~InstanceCount() { --instance_count_; }

  static int instance_count() {
    return instance_count_;
  }

 private:
  static int instance_count_;
};

int InstanceCount::instance_count_ = 0;

    // smartpoint ,smartpoint1 call constructor function.
	// smartpoint->data_->RefCounted == 1
	// smartpoint1->data_->RefCounted == 1
	SmartPointer<InstanceCount> smartpoint ( new InstanceCount());  
	cout<<InstanceCount::instance_count();
	SmartPointer<InstanceCount> smartpoint1 ( new InstanceCount()); 
	cout<<InstanceCount::instance_count();
	
	// smartpoint2 call copy connstructor function.
	//          data_->RefCounted == 2
	//          /   \
	//  smartpoint   smartpoint2
	SmartPointer<InstanceCount> smartpoint2 = smartpoint;
	cout<<InstanceCount::instance_count();

	// smartpoint1 call assignment function.
	//                data_     ->RefCounted == 3
	//         /       |      \
	//  smartpoint smartpoint2 smartpoint1
	smartpoint1 = smartpoint;
*/