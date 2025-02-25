// This file is made available under Elastic License 2.0.
// This file is based on code available under the Apache license here:
//   https://github.com/apache/incubator-doris/blob/master/be/src/util/url_coding.h

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

#include <boost/cstdint.hpp>
#include <string>
#include <vector>

namespace starrocks {

// Utility method to URL-encode a string (that is, replace special
// characters with %<hex value in ascii>).
// The optional parameter hive_compat controls whether we mimic Hive's
// behaviour when encoding a string, which is only to encode certain
// characters (excluding, e.g., ' ')
void url_encode(const std::string& in, std::string* out);
void url_encode(const std::vector<uint8_t>& in, std::string* out);

// Utility method to decode a string that was URL-encoded. Returns
// true unless the string could not be correctly decoded.
// The optional parameter hive_compat controls whether or not we treat
// the strings as encoded by Hive, which means selectively ignoring
// certain characters like ' '.
bool url_decode(const std::string& in, std::string* out);

void base64url_encode(const std::string& in, std::string* out);
void base64_encode(const std::string& in, std::string* out);

// Utility method to decode base64 encoded strings.  Also not extremely
// performant.
// Returns true unless the string could not be correctly decoded.
bool base64_decode(const std::string& in, std::string* out);

// Replaces &, < and > with &amp;, &lt; and &gt; respectively. This is
// not the full set of required encodings, but one that should be
// added to on a case-by-case basis. Slow, since it necessarily
// inspects each character in turn, and copies them all to *out; use
// judiciously.
void escape_for_html(const std::string& in, std::stringstream* out);

} // namespace starrocks
