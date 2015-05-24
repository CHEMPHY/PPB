
###############Plasma Protein Binding (PPB) Prediction ###################
#Author:Mengyuan Zhu
#Email: mzhu7@gsu.edu
#Georgia State University
#Usage: PPB_calculate.py filename
##########################################################################


import pybel
from ctypes import *
import sys
import pybel

lib=CDLL("lib/ppblib.so")
inputfile=pybel.readfile(sys.argv[1].split(".")[-1],sys.argv[1])
value=()


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
	
	smarts = pybel.Smarts("[+]")
	num=smarts.findall(mol)				
	value= value+(len(num),)			
	
	smarts = pybel.Smarts("[-]")
	num=smarts.findall(mol)				
	value= value+(len(num),)
	

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
