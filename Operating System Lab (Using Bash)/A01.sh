#1. UNIX Commands & Permissions 
#a. cal, date, pwd, mkdir, cd, rmdir, Is, Is -l, cat, cp, mv, rm, wc 
#b. uname, man, who, whoami, echo, grep, chmod

# Displays a text-based calendar
function demonstrate_cal() {
    cal
    cal 2026
}

# Displays or sets the system date and time
function demonstrate_date() {
    date
    date "+%Y-%m-%d %H:%M:%S"
}

# Prints the absolute path of the current working directory
function demonstrate_pwd() {
    pwd
}

# Creates one or more new directories
function demonstrate_mkdir() {
    mkdir new_folder
    mkdir -p parent/child_folder
}

# Changes the current working directory
function demonstrate_cd() {
    cd /path/to/directory
    cd ..
    cd ~
}

# Deletes empty directories
function demonstrate_rmdir() {
    rmdir empty_folder
}

# Lists directory contents
function demonstrate_ls() {
    ls
    ls -l
    ls -la
}

# Reads and concatenates file contents to standard output
function demonstrate_cat() {
    cat file.txt
    cat file1.txt file2.txt > merged.txt
}

# Copies files or directories from source to destination
function demonstrate_cp() {
    cp source.txt destination.txt
    cp -r source_folder/ destination_folder/
}

# Moves or renames files or directories
function demonstrate_mv() {
    mv old_name.txt new_name.txt
    mv file.txt /path/to/destination_folder/
}

# Removes files or directories permanently
function demonstrate_rm() {
    rm file.txt
    rm -r folder_name
    rm -f file.txt
}

# Counts lines, words, and bytes in a file
function demonstrate_wc() {
    wc file.txt
    wc -l file.txt
}

# Prints system hardware and kernel architecture details
function demonstrate_uname() {
    uname
    uname -a
}

# Opens the reference manual for a command
function demonstrate_man() {
    man ls
    man grep
}

# Displays users currently logged into the system
function demonstrate_who() {
    who
}

# Prints the active user's effective username
function demonstrate_whoami() {
    whoami
}

# Prints text strings or variables to standard output
function demonstrate_echo() {
    echo "Hello World"
    echo "Current user is: $USER"
}

# Searches for patterns within text or files
function demonstrate_grep() {
    grep "search_term" filename.txt
    grep -i "case_insensitive" filename.txt
    history | grep "previous_command"
}

# Modifies file or directory access permissions
function demonstrate_chmod() {
    chmod 755 script.sh   
    chmod 644 document.txt
    chmod 700 private.key 
    chmod u+x script.sh   
    chmod g-w document.txt
}

