/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include <memory>

#include <google/protobuf/message.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include "bytes.h"


#include "../rpc/generated/Filter.pb.h"

class ByteArrayComparable {

 public:
  ByteArrayComparable();
  ByteArrayComparable(const BYTE_ARRAY &value);
  virtual ~ByteArrayComparable();

  int GetValue(BYTE_ARRAY &value);
  bool AreSerializedFieldsEqual(ByteArrayComparable &other);
  int CompareTo(const BYTE_ARRAY &value);

  static ByteArrayComparable *ParseFrom(const BYTE_ARRAY &pb_bytes);

  virtual int CompareTo(const BYTE_ARRAY &value, const int &offset, const int &length);

  std::unique_ptr<google::protobuf::Message> Convert();

  virtual const char *GetName() = 0;
  virtual int ToByteArray(std::string &serialized_string) = 0;

 private:
  BYTE_ARRAY value_;
};
