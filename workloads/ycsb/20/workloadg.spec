# Yahoo! Cloud System Benchmark
# Workload A: Update heavy workload
#   Application example: Session store recording recent actions
#
#   Read/update ratio: 50/50
#   Default data size: 1 KB records (10 fields, 100 bytes each, plus key)
#   Request distribution: zipfian

recordcount=1638400
operationcount=0
workload=com.yahoo.ycsb.workloads.CoreWorkload

readallfields=true
writeallfields=true

fieldcount=1
fieldlength=65536

readproportion=0
updateproportion=0
scanproportion=0
insertproportion=1

requestdistribution=zipfian

