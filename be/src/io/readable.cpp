// This file is licensed under the Elastic License 2.0. Copyright 2021-present, StarRocks Limited.

#include "io/readable.h"

namespace starrocks::io {

Status Readable::read_fully(void* data, int64_t count) {
    int64_t nread = 0;
    while (nread < count) {
        ASSIGN_OR_RETURN(auto n, read(data + nread, count - nread));
        nread += n;
        if (n == 0) {
            return Status::IOError("cannot read fully");
        }
    }
    return Status::OK();
}

} // namespace starrocks::io
