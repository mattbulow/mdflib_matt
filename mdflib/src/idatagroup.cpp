/*
 * Copyright 2021 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "mdf/idatagroup.h"

#include <algorithm>

namespace mdf {

void IDataGroup::AttachSampleObserver(ISampleObserver *observer) const {
  observer_list.emplace_back(observer);
}

void IDataGroup::DetachSampleObserver(const ISampleObserver *observer) const {
  for (auto itr = observer_list.begin(); itr != observer_list.end();
       /* No ++itr here */) {
    if (*itr == observer) {
      itr = observer_list.erase(itr);
    } else {
      ++itr;
    }
  }
}

void IDataGroup::DetachAllSampleObservers() const { observer_list.clear(); }

void IDataGroup::NotifySampleObservers(
    size_t sample, uint64_t record_id,
    const std::vector<uint8_t> &record) const {
  for (auto *observer : observer_list) {
    if (observer != nullptr) {
      observer->OnSample(sample, record_id, record);
    }
  }
}

void IDataGroup::ResetSample() const {
  auto list = ChannelGroups();
  std::for_each(list.begin(),list.end(),
                        [](const auto *cg) { cg->ResetSample(); });
}

IMetaData *IDataGroup::CreateMetaData() { return nullptr; }

const IMetaData *IDataGroup::MetaData() const { return nullptr; }

void IDataGroup::Description(const std::string &) {}

std::string IDataGroup::Description() const { return {}; }

void IDataGroup::RecordIdSize(uint8_t id_size) {}

uint8_t IDataGroup::RecordIdSize() const { return 0; }

}  // namespace mdf
