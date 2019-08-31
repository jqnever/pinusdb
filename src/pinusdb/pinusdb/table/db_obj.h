#pragma once

#include "internal.h"
#include "table/db_value.h"
#include "table/table_info.h"
#include "util/arena.h"

class DBObj
{
public:
  DBObj(Arena* pArena) : pArena_(pArena) {}
  ~DBObj() {}

  void Clear();

  size_t GetFieldCnt() const;
  const DBVal* GetFieldValue(size_t idx) const;

  void AppendNullVal();
  void AppendVal(bool val);
  void AppendVal(int64_t val);
  void AppendVal(double val);
  PdbErr_t AppendStrVal(const char* pVal, size_t len);
  PdbErr_t AppendBlobVal(const PdbByte* pVal, size_t len);
  void AppendDateTime(int64_t val);

  PdbErr_t AppendVal(const DBVal* pVal);

  PdbErr_t GetTransLen(size_t* pTotalLen);
  PdbErr_t SerializeToTrans(PdbByte* pBuf, size_t* pTotalLen);

  PdbErr_t ParseTrans(size_t fieldCnt, const PdbByte* pData, const PdbByte* pLimit, size_t* pObjLen);

private:
  Arena* pArena_;
  std::vector<DBVal> fieldVec_;
};
