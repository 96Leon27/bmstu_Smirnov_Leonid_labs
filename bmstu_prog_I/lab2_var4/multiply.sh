#!/bin/bash
if [$# -ne 2]; then
  echo "Нажно два множителя"
  exit 1;
fi
n1=$1
n2=$2
echo $(($1 * $2))
