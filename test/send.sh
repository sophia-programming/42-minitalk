SERVER_PID=`ps | grep './server' | grep -v "grep" | awk '{ print $1 }'`

./client ${SERVER_PID} ${1}
