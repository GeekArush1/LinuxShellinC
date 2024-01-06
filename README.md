[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/76mHqLr5)
# Description
Project Title: Custom Linux Shell Implementation in C

**Introduction:**

Developed during the Operating Systems and Networks course at IIIT Hyderabad, this project focuses on creating a customized Linux Shell in the C programming language.
Shell Interface:

Upon opening, the shell presents a unique display as "ArushSachdeva@Shell," providing a personalized user experience.

**Input Handling:**

Supports a ';'- or '&' - separated list of commands.
Utilizes 'strtok' for input tokenization.
Accommodates random spaces and tabs in the input.
';' enables the execution of multiple commands simultaneously.
'&' runs the succeeding command in the background, displaying the process ID of the newly created process.

**Directory Navigation ('warp' Command):**

Allows changing the current directory with the 'warp' command.
Prints the full path of the working directory after changing.
Supports flags such as '.', '..', '~', and '-'.
Accepts both absolute paths and paths from the home directory.

**File and Directory Listing ('peek' Command):**

Lists files and directories in lexicographic order.
Supports '-a' and '-l' flags for displaying hidden files and additional information.
Similar to 'warp,' supports symbols like '.', '..', '~', and '-'.

**Persistent Command History ('pastevents' Command):**

Stores and outputs the 15 most recent command statements.
Overwrites the oldest commands if the limit is reached.
Persists across different shell runs.

**System Commands Execution:**

Executes both foreground and background system commands present in Bash.
Reports time and process name for foreground processes taking > 2 seconds.
Prints the PID of a newly created background process.

**Process Information Retrieval ('proclore' Command):**

Retrieves information about a process, including PID, status, process group, virtual memory, and executable path.
Distinguishes between foreground and background processes.

**File/Direcory Search ('seek' Command):**

Searches for files or directories in the specified target directory.
Supports flags for specific search types (-d, -f, -e).
Returns a list of relative paths of matching files/directories.
**Pipes and Data Transfer:**

Supports any number of pipes for passing information between commands.
Handles sequential execution of commands from left to right.

**Process Monitoring ('activities' Command):**

Prints a list of all processes spawned by the shell, including command name, PID, and state (running or stopped).

**Signal Handling ('ping' Command):**

Sends signals to processes using the 'ping' command.
Takes PID and signal number as arguments, with error handling for non-existent processes.

**Interrupt Handling:**

Implements Ctrl-C to interrupt currently running foreground processes.
Implements Ctrl-D to log out of the shell while killing all processes.

**Background Process Management ('fg' and 'bg' Commands):**

Brings a running or stopped background process to the foreground using 'fg.'
Changes the state of a stopped background process to running with 'bg.'

**Process Monitoring ('Neonate' Command):**

Monitors the most recently created process, printing its Process-ID every [time_arg] seconds until 'x' is pressed.

**Networking:**

Implements 'iMan' command to fetch man pages from http://man.he.net/ using sockets.
Utilizes DNS resolution and TCP socket communication for fetching and displaying man pages.

**Conclusion:**
This comprehensive Linux Shell project showcases proficiency in system programming concepts, emphasizing usability, efficiency, and a wide range of features for both novice and advanced users. The detailed pointwise features make it an ideal addition to GitHub for educational and collaborative purposes.
# Assumptions
Every background process can be forked with & but there should be no space between the camoomand and '&'.

A flag has to be mentioned in peek() function everytime

Flags in peek function should be passed without any space.
