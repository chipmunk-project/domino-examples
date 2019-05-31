import subprocess
import sys

"""
This program runs domino automatically.
In ~/domino-examples folder run:

python3 marple_new_flow banzai_atoms/pred_raw.sk 10 

It will output how many mutators successfully compile with atoms provided.
"""

if (len(sys.argv) != 4):
   print("Usage: python3 " + argv[0] + " <domino program filename> <atom file> <number of mutators> ")
   sys.exit(1)
# Sum stores the total number of successful compilation files
Sum = 0
# program_file stores the domino program file name
program_file_name = sys.argv[1]
# atom_file stores the atom used by domino
atom_file = sys.argv[2]
# num_of_mutator stores the total number of mutator files
num_of_mutators = int(sys.argv[3])
for i in range(num_of_mutators):
  program_file = "/tmp/" + program_file_name + "_equivalent_" + str(i+1) + ".c"
  print(program_file)
  # Now we just set the pipeline width and depth to be 20 10
  (ret_code,output) = subprocess.getstatusoutput('domino ' + program_file + ' ' + atom_file
                                               + ' 20 10')
  if (output.find("/tmp/debug") == -1 and ret_code == 0):
    print("Successful file is No." + str(i+1))
    Sum += 1

print("The successful compilation rate for " + program_file_name +
      "mutators is " + str(Sum/num_of_mutators))
