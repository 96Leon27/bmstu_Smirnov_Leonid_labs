#!/bin/bash
while true; do
echo "message recieved" | nc -l -p 3721
done
