#!/bin/bash

BLUE='\033[0;34m'
RED='\033[31m'
NC='\033[0m'

function message() {
    echo -e "${BLUE}[dmitrievmyshell] $1${NC}"
}

function error() {
    echo -e "${RED}[dmitrievmyshell] Error: $1${NC}"
}
