import subprocess
import sys
import re

"""
This program runs domino automatically.
In ~/domino-examples folder run:

python3 run_domino_automatically.py marple_new_flow banzai_atoms/pred_raw.sk 10 

It will output how many mutators successfully compile with atoms provided.
"""

if (len(sys.argv) != 4):
   print("Usage: python3 " + argv[0] + 
        " <domino program filename> <atom file> <number of mutators> ")
   sys.exit(1)
# Sum stores the total number of successful compilation files
Sum = 0
# program_file stores the domino program file name
program_file_name = sys.argv[1]
# atom_file stores the atom used by domino
atom_file = sys.argv[2]
# num_of_mutator stores the total number of mutator files
num_of_mutators = int(sys.argv[3])

# total_num_of_stages stores the total number of stages used across all mutator files
total_num_of_stages = 0
# total_num_of_width stores the total number of ALUs used per stage
total_num_of_width = 0

(_,_) = subprocess.getstatusoutput('mutator domino_programs/' + program_file_name + '.c')

for i in range(num_of_mutators):
  program_file = "/tmp/" + program_file_name + "_equivalent_" + str(i+1) + ".c"
  print(program_file)
  # Now we just set the pipeline width and depth to be 20 10
  (ret_code,output) = subprocess.getstatusoutput('domino ' + program_file + 
                                                 ' ' + atom_file + ' 20 10')
  if (output.find("/tmp/debug") == -1 and ret_code == 0):
    print("Successful file is No." + str(i+1))
    length = re.findall(r"Total of (\d+) stages", output)
    width = re.findall(r"Maximum of (\d+) codelets/stage", output)
    total_num_of_stages += int(length[0])
    total_num_of_width += int(width[0])
    print("The number of stages for " + program_file + " is: " + length[0])
    print("The number of ALUs per stage for " + program_file + " is: " + width[0])
    Sum += 1

print("The successful compilation rate for " + program_file_name +
      "mutators by domino is " + str(Sum/num_of_mutators))
if (Sum > 0):
    print("The avg num of stages is: " + str(total_num_of_stages/Sum))
    print("The avg num of ALUs per stage is: " + str(total_num_of_width/Sum))
