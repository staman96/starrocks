// This file is made available under Elastic License 2.0.
// This file is based on code available under the Apache license here:
//   https://github.com/apache/incubator-doris/blob/master/be/src/util/null_load_error_hub.h

// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <mutex>
#include <queue>
#include <sstream>
#include <string>

#include "load_error_hub.h"

namespace starrocks {

//  do not export error.
//  only record some metric to some memory(like total error row) for now.

class NullLoadErrorHub : public LoadErrorHub {
public:
    NullLoadErrorHub();

    ~NullLoadErrorHub() override;

    Status prepare() override;

    Status export_error(const ErrorMsg& error_msg) override;

    Status close() override;

    std::string debug_string() const override;

private:
    std::mutex _mtx;
    std::queue<ErrorMsg> _error_msgs;

}; // end class NullLoadErrorHub

} // end namespace starrocks
