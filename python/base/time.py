#!/usr/bin/python
# -*- coding: utf-8 -*-

import time
import datetime

timeStamp = 1381419600
timeArray = time.localtime(timeStamp)
otherStyleTime = time.strftime("%Y%m%d", timeArray)
print(otherStyleTime)   # 2013--10--10 23:40:00