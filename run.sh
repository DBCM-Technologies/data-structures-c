#!/bin/sh

set -e

ex() {
    echo "$@"
    $@
}

PRG=${1/%.c/}
CFLAGS="-g -Werror -Wall -Wextra -pedantic -std=c89"
ex cc $CFLAGS -o $PRG ${1}
ex ./$PRG