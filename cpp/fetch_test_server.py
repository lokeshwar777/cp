import os
import json
import subprocess
from flask import Flask, request, jsonify

app = Flask(__name__)
PORT = 10045  # Must match Competitive Companion's custom port


def find_cpp_file():
    for file in os.listdir():
        if file.endswith(".cpp"):
            return file
    return None


def clean(text):
    return text.replace('\r', '').strip()


def save_tests(data):
    cpp_file = find_cpp_file()
    if not cpp_file:
        return "[!] No .cpp file found."

    test_file = cpp_file + "__tests"
    tests = []

    inputs = data.get("tests", [])
    for test in inputs:
        tests.append({
            "correct_answers": [clean(test.get("output", ""))],
            "test": clean(test.get("input", "")) + '\n',
        })

    with open(test_file, "w") as f:
        json.dump(tests, f, indent=2)

    return f"[✓] Test cases saved to {test_file}"


'''
def trigger_sublime_build():
    try:
        subprocess.run([
            "osascript", "-e",
        ])
        print("[✓] Triggered build in Sublime Text")
    except Exception as e:
        print("[!] Failed to trigger build:", e)
'''


@app.route("/", methods=["POST"])
def receive_testcases():
    data = request.get_json()
    if not data:
        return jsonify({"status": "error", "message": "No data received"}), 400

    print("[>] Received test cases from Competitive Companion")
    result = save_tests(data)
    print(result)

    # trigger_sublime_build()
    return jsonify({"status": "ok"})


if __name__ == "__main__":
    print(f"[i] Server listening on http://localhost:{PORT}")
    app.run(port=PORT)
