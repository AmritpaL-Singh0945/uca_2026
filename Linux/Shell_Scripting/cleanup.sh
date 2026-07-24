#!/bin/bash

sed -i -E \
  -e '/^#/d' \
  -e 's/HTTP\/1\.0/HTTP\/1.1/g' \
  -e 's/[0-9]{4}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g' \
  server_access.log