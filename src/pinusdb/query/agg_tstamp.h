/*
* Copyright (c) 2019 ChangSha JuSong Soft Inc. <service@pinusdb.cn>.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 3 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program; If not, see <http://www.gnu.org/licenses>
*/

#pragma once

#include "internal.h"
#include "query/result_field.h"

class GroupTstampField : public ResultField
{
public:
  GroupTstampField(int64_t tstamp)
  {
    tstamp_ = tstamp;
  }

  virtual ~GroupTstampField() {}
  
  virtual int32_t FieldType() { return PDB_FIELD_TYPE::TYPE_DATETIME; }

  virtual PdbErr_t AppendData(const DBVal* pVals, size_t valCnt)
  {
    return PdbE_OK;
  }

  virtual PdbErr_t GetResult(DBVal* pVal)
  {
    DBVAL_SET_DATETIME(pVal, tstamp_);
    return PdbE_OK;
  }

  virtual ResultField* NewField(int64_t devId, int64_t tstamp)
  {
    return new GroupTstampField(tstamp);
  }

private:
  int64_t tstamp_;
};
