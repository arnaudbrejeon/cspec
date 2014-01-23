#!/bin/sh

UNAMES=`uname -s`

case "x$UNAMES" in
  "xDarwin")
    LIBTOOLIZE=glibtoolize
    ;;
  "xFreeBSD" | "xLinux" | "xSunOS")
    LIBTOOLIZE=libtoolize
    ;;
  *)
    echo "WARNING: unrecognized platform: x$UNAMES"
    LIBTOOLIZE=libtoolize
esac

set -ex

mkdir -p m4

aclocal -I m4

$LIBTOOLIZE --copy --force

automake --force-missing --add-missing --copy --foreign 

autoconf

