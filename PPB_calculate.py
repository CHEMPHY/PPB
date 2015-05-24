import pybel
from ctypes import *
import sys
import pybel

lib=CDLL("lib/ppblib.so")
inputfile=pybel.readfile(sys.argv[1].split(".")[-1],sys.argv[1])
value=()
num_molecule=0

for mol in inputfile:
	descvalues=mol.calcdesc()
	value= value+(descvalues.get('TPSA'),)
	value= value+(descvalues.get('HBD'),)
	value= value+(descvalues.get('logP'),)
	value= value+(descvalues.get('MW'),)
	value= value+(descvalues.get('tbonds'),)
	value= value+(descvalues.get('nF'),)
	value= value+(descvalues.get('bonds'),)
	value= value+(descvalues.get('atoms'),)
	value= value+(descvalues.get('HBA1'),)
	value= value+(descvalues.get('HBA2'),)
	value= value+(descvalues.get('sbonds'),)
	value= value+(descvalues.get('dbonds'),)
	value= value+(descvalues.get('MR'),)
	value= value+(descvalues.get('abonds'),)
	maccsfile = open("MACCS.txt", 'r')
	while True:
		line_maccs=maccsfile.readline()
		
		if not line_maccs:
			break
		if line_maccs.find(":")>0:
			line_maccs=line_maccs[line_maccs.find("'")+1:line_maccs.rfind("'")]
			if len(line_maccs)>0:
				smarts = pybel.Smarts(line_maccs)
				num=smarts.findall(mol)				
				value= value+(len(num),)			
	maccsfile.close()
	line=0

i=0
array_type=c_double*16
value_c=array_type()
while i<16:
	
	value_c[i]=value[i]
	i=i+1

function=lib.PPB_ann
function.restype=c_double
result= function(byref(value_c))

if result >100:
	result=100
if result<0:
	result=0
print round(result,2)
