# Yahoo! Cloud System Benchmark
# Workload A: Update heavy workload
#   Application example: Session store recording recent actions
#                        
#   Read/update ratio: 50/50
#   Default data size: 1 KB records (10 fields, 100 bytes each, plus key)
#   Request distribution: zipfian

recordcount=3125000
operationcount=3125000
workload=com.yahoo.ycsb.workloads.CoreWorkload

readallfields=true

fieldcount=1
fieldlength=4096

readproportion=0
updateproportion=1
scanproportion=0
insertproportion=0

requestdistribution=zipfian


