#!/bin/bash

cd ~/developer/cp/cpp

# Start Flask server in the background and save its PID to a file
python3 fetch_test_server.py > flask_server.log 2>&1 &
SERVER_PID=$!
echo "[i] Flask server started with PID $SERVER_PID"

# Open Sublime project
open -a "Sublime Text" loki-cp.sublime-project
echo "[i] Waiting for Sublime Text to exit..."

# Dynamically get the PID of the main Sublime Text process (first one)
SUBLIME_PID=$(pgrep -f "Sublime Text" | head -n 1)

# Check if Sublime Text is running
if [ -z "$SUBLIME_PID" ]; then
  echo "[!] Sublime Text is not running."
  exit 1
fi

echo "[i] Monitoring Sublime Text with PID: $SUBLIME_PID"

# Wait until the main Sublime Text process is no longer running
while ps -p $SUBLIME_PID > /dev/null; do
  sleep 2
done

# Check if the Flask server is still running before attempting to kill it
if ps -p $SERVER_PID > /dev/null; then
  echo "[i] Sublime Text closed. Gracefully stopping Flask server..."
  kill -15 $SERVER_PID > /dev/null 2>&1  # suppress termination message
  wait $SERVER_PID 2>/dev/null           # suppress wait output
  echo "[i] Flask server stopped."
else
  echo "[!] Flask server process not found, already terminated."
fi

# Optional: Delete the log file after server stops
echo "[i] Deleting flask_server.log"
rm -f flask_server.log
