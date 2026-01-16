import subprocess
from flask import Flask, request, send_file

app = Flask(__name__)

# START C++ PROGRAM
# bufsize=0 ensures we get output immediately
'''proc = subprocess.Popen(
    ['main.exe'], 
    stdin=subprocess.PIPE, 
    stdout=subprocess.PIPE, 
    text=True, 
    bufsize=0 
)'''
proc = subprocess.Popen(
    ['app.exe'],   # ← FIXED
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    bufsize=0
)


def get_cpp_response():
    """Reads C++ output character-by-character to avoid blocking."""
    output = ""
    while True:
        # Read 1 character at a time
        char = proc.stdout.read(1) 
        if not char: break
        output += char
        
        # Stop reading when we see the menu prompt
        if output.endswith("Enter choice: "):
            break
            
    # Clean up the menu text so only the result remains
    clean_out = output.replace("Enter choice: ", "")
    clean_out = clean_out.replace("====== Document Analyzer ======", "")
    clean_out = clean_out.replace("1. Load Document", "")
    clean_out = clean_out.replace("2. Ask a Question", "")
    clean_out = clean_out.replace("3. Search Word & Count", "")
    clean_out = clean_out.replace("4. Show Concept Graph", "")
    clean_out = clean_out.replace("5. Show Question History", "")
    clean_out = clean_out.replace("0. Exit", "")
    return clean_out.strip()

# INITIAL SETUP
print("Initializing C++ Backend...")
# 1. Read the initial menu (character by character now, so it won't hang)
get_cpp_response()       

# 2. Select Option 1 (Load Document)
proc.stdin.write("1\n")  
proc.stdin.flush()

# 3. Read the 'Document loaded' message
print(get_cpp_response())       
print("Ready! Server running on http://localhost:5000")

# --- ROUTES ---

@app.route('/')
def home(): return send_file('index.html')

@app.route('/style.css')
def css(): return send_file('style.css')

@app.route('/load')
def load_doc():
    proc.stdin.write("1\n") 
    proc.stdin.flush()
    return get_cpp_response()

@app.route('/ask')
def ask():
    q = request.args.get('q')
    proc.stdin.write(f"2\n{q}\n") 
    proc.stdin.flush()
    return get_cpp_response().replace("Ask a question:", "").strip()

@app.route('/search')
def search():
    w = request.args.get('word')
    proc.stdin.write(f"3\n{w}\n") 
    proc.stdin.flush()
    return get_cpp_response().replace("Enter word to search:", "").strip()

@app.route('/graph')
def show_graph():
    proc.stdin.write("4\n") 
    proc.stdin.flush()
    return get_cpp_response()

@app.route('/history')
def show_history():
    proc.stdin.write("5\n") 
    proc.stdin.flush()
    return get_cpp_response()

if __name__ == '__main__':
    app.run(port=5000)