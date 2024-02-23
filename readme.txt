Title:
MAC_PDU decoding

Description:
MAC PDU consists of string of bytes.   MAC PDU consists of MAC header + MAC Control Element + MAC SDU.   We will start with decoding MAC header for DL-SCH. MAC header consists of MAC sub-headers.  

Dependencies:
OS -Linux
Platform- VS Code

To compile:
give a command "make" in the same where files are present.
or
g++ -Wall <main.cpp> <dependency_files> -o <executable_file_name>

To run
./<executable_file_name> 
or 
<target_name>