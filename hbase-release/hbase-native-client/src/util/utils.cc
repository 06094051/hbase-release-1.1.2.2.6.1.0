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

#include "utils.h"


CommonUtils::CommonUtils() {
  // TODO Auto-generated constructor stub

}

CommonUtils::~CommonUtils() {
  // TODO Auto-generated destructor stub
}

void CommonUtils::SwapByteOrder(unsigned int &ui)
{
  ui = (ui >> 24) |
      ((ui<<8) & 0x00FF0000) |
      ((ui>>8) & 0x0000FF00) |
      (ui << 24);
}

void CommonUtils::SwapByteOrder2Bytes(unsigned short &us) {
  us = ( (((us) >> 8) & 0x00FF) | (((us) << 8) & 0xFF00) );
}

