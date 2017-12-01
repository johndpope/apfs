/*
 * Copyright (c) 2017-present Orlando Bassotto
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __apfs_fuse_xattr_file_h
#define __apfs_fuse_xattr_file_h

#include "file.h"

#include "xattr_directory.h"
#include "xattr_object_directory.h"

namespace apfs_fuse {

class xattr_file : public file {
private:
    std::string _xattr;

protected:
    friend class volume;
    xattr_file(apfs::object *o, std::string const &xattr);

public:
    uint64_t get_size() const override;

public:
    bool is_directory() const override;
    bool is_symbolic_link() const override;
    bool is_regular() const override;
    bool is_virtual() const override;

public:
    int getattr(struct stat *st) const override;

public:
    ssize_t read(void *buf, size_t size, off_t offset) const override;
};

}

#endif  // !__apfs_fuse_xattr_file_h
