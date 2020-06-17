import subprocess
import sys
import re

"""
This program runs domino automatically.
In ~/domino-examples folder run:

python3 run_expr.py 

It will output how many mutators successfully compile with atoms provided.
"""

program_file_list = ["blue_increase", "blue_decrease", "conga",
                     "flowlets", "learn_filter", "marple_new_flow",
                     "marple_tcp_nmo", "rcp", "sampling",
                     "snap_heavy_hitter", "spam_detection", "stateful_fw",
                     "stfq","dns_ttl_change"]
atom_file_list = ["pred_raw.sk", "sub.sk", "pair.sk", "pred_raw.sk",
                  "raw.sk", "pred_raw.sk", "pred_raw.sk", "pred_raw.sk",
                  "if_else_raw.sk", "pair.sk", "pair.sk", "pred_raw.sk",
                  "nested_ifs.sk", "nested_ifs.sk"]

for i in range(len(program_file_list)):
    program_name = program_file_list[i]
    atom_name = atom_file_list[i]
    (_,_) = subprocess.getstatusoutput('mutator domino_programs/' + program_name + '.c')
    (ret_code, output) = subprocess.getstatusoutput('python3 run_domino_automatically.py ' + \
                                                    program_name + \
                                                    ' banzai_atoms/' + atom_name + ' 10')
    print('program_name =', program_name)
    print('ret_code =', ret_code)
    print('output = ', output)
    print('----------------------------------------------\n')
