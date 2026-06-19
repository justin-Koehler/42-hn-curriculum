#!/bin/bash
id --groups -n $FT_USER | tr ' ' ',' | tr -d '\n'
