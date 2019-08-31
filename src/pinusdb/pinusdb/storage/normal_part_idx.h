#pragma once
#include "internal.h"
#include "port/os_file.h"
#include "util/arena.h"
#include "util/skip_list.h"
#include "util/date_time.h"
#include <unordered_map>

typedef struct _DataIdxComp
{
  int operator()(uint32_t keyA, uint32_t keyB) const
  {
    return keyA == keyB ? 0 : (keyA > keyB ? -1 : 1);
  }
}DataIdxComp;

typedef SkipList<uint32_t, int32_t, DataIdxComp> DataIdxSkipList;

typedef struct _NormalPageIdx
{
  int64_t devId_;
  int64_t idxTs_;
  int32_t pageNo_;
  char    pad12[12];
}NormalPageIdx;

class NormalPartIdx
{
public:
  NormalPartIdx();
  ~NormalPartIdx();

  static PdbErr_t Create(const char* pPath, int32_t partCode);

  PdbErr_t Open(const char* pPath, bool readOnly);
  PdbErr_t Close();

  PdbErr_t AddIdx(int64_t devId, int64_t idxTs, int32_t pageNo);
  PdbErr_t WriteIdx(const std::vector<NormalPageIdx>& idxVec);

  PdbErr_t GetIndex(int64_t devId, int64_t ts, NormalPageIdx* pIdx);
  PdbErr_t GetPrevIndex(int64_t devId, int64_t ts, NormalPageIdx* pIdx);
  PdbErr_t GetNextIndex(int64_t devId, int64_t ts, NormalPageIdx* pIdx);

  int32_t GetPartCode() const { return static_cast<int32_t>(bgDayTs_ / MillisPerDay); }
  int32_t GetMaxPageNo() const { return maxPageNo_; }

  void GetAllDevId(std::vector<int64_t>& devIdVec);

private:
  OSFile idxFile_;
  std::string idxPath_;
  size_t curPos_;        //��һ��д��������ļ�λ��
  int64_t bgDayTs_;
  int64_t edDayTs_;

  bool readOnly_;
  int32_t maxPageNo_;     //��ǰ���ʹ�õ�����ҳ

  std::mutex idxMutex_;
  std::mutex fileMutex_;
  Arena arena_;
  std::unordered_map<int64_t, DataIdxSkipList*> idxMap_;
};

