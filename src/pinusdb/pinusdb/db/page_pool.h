#pragma once

#include "internal.h"

#include <unordered_map>
#include <mutex>
#include <vector>
#include <list>
#include <atomic>
#include "storage/page_hdr.h"
#include "util/ref_util.h"

#define PDB_PAGEPOOL_DATAFILE_MASK    (0xFFFFFFFF00000000)
#define PDB_PAGEPOOL_TABLE_MASK       (0xFF00000000000000)

class PagePool
{
public:
  PagePool();
  ~PagePool();

  bool InitPool();
  void Stop();
  size_t GetPoolPageCnt() { return totalCacheSize_ / NORMAL_PAGE_SIZE; }
  PdbErr_t GetPage(uint64_t pageCode, PageRef* pPageRef);

  void ClearPageForMask(uint64_t pageCode, uint64_t maskCode);

private:
  PageHdr* _GetFreePage();
  void _PutFreePage(PageHdr* pPage);
  PdbErr_t _AllocCache();

private:
  enum {
    kAllocSize = PDB_MB_BYTES(128),  //一次内存申请大小 128M
    kErrorCoolingTime = (60 * 1000), // 内存申请失败后的冷却时间
  };

private:
  bool running_;

  std::mutex poolMutex_;

  struct list_head readList_;
  struct list_head freeList_;

  size_t totalCacheSize_;  //总的缓存大小
  size_t useCacheSize_;    //已使用的缓存大小 

  uint64_t lastAllocErrorTime_; //上次申请失败的时间

  std::vector<uint8_t*> hdrVec_;
  std::vector<void*> cacheMemVec_;
  std::unordered_map<uint64_t, PageHdr*> pageMap_;
};

