#ifndef COMMON_H
#define COMMON_H

template <typename T>
int compare(const T &a, const T &b) {
  if (a < b) {
    return -1;
  } else if (a == b) {
    return 0;
  } else {
    return 1;
  }
}

#endif
