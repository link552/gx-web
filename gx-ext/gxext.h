#include "gx.hh"

namespace gx {
    inline String operator+(const String &a, const String &b) {
        String s;
        s.data.insert(s.data.end() - 1, a.data.begin(), a.data.end() - 1);
        s.data.insert(s.data.end() - 1, b.data.begin(), b.data.end() - 1);
        return s;
    }
}
