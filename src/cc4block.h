/*
 * Copyright 2021 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include <vector>
#include <string>
#include <limits>
#include <variant>
#include "iblock.h"
#include "mdf/ichannelconversion.h"
#include "md4block.h"

namespace mdf::detail {


 class Cc4Block : public IBlock, public IChannelConversion {
 public:
   using RefList = std::vector<std::unique_ptr<IBlock>>;
   using ParameterList = std::vector<std::variant<uint64_t, double>>;

   Cc4Block();

   [[nodiscard]] int64_t Index() const override;;
   void Name(const std::string &name) override;

   [[nodiscard]] std::string Name() const override;

   void Unit(const std::string &unit) override;
   [[nodiscard]] std::string Unit() const override;

   void Description(const std::string &desc) override;
   [[nodiscard]] std::string Description() const override;

   void Type(ConversionType type) override;
   [[nodiscard]] ConversionType Type() const override;

   void Decimals(uint8_t decimals) override;
   [[nodiscard]] uint8_t Decimals() const override;

   [[nodiscard]] bool IsUnitValid() const override;
   [[nodiscard]] bool IsDecimalUsed() const override;

   [[nodiscard]] IChannelConversion *CreateInverse() override;
   [[nodiscard]] const IChannelConversion *Inverse() const override;

   void Range(double min, double max) override;
   [[nodiscard]] std::optional<std::pair<double, double>> Range() const override;

   void Flags(uint16_t flags) override;
   [[nodiscard]] uint16_t Flags() const override;

  [[nodiscard]] const Cc4Block* Cc() const {
    return cc_block_.get();
  }

  [[nodiscard]] const RefList& References() const {
    return ref_list_;
  }

  [[nodiscard]] const IBlock* Find(fpos_t index) const override;
  void GetBlockProperty(BlockPropertyList& dest) const override;

  size_t Read(std::FILE *file) override;
  size_t Write(std::FILE *file) override;

 protected:
  bool ConvertValueToText(double channel_value, std::string& eng_value) const override;
  bool ConvertValueRangeToText(double channel_value, std::string& eng_value) const override;
  bool ConvertTextToValue(const std::string& channel_value, double& eng_value) const override;
  bool ConvertTextToTranslation(const std::string& channel_value, std::string& eng_value) const override;
 private:
  uint8_t type_ = 0;
  uint8_t precision_ = 0;
  uint16_t flags_ = 0;
  uint16_t nof_references_ = 0;

  double range_min_ = 0;
  double range_max_ = 0;

  std::string name_;
  std::unique_ptr<Cc4Block> cc_block_; ///< Inverse conversion block
  std::unique_ptr<Md4Block> unit_;
  RefList ref_list_;
};

}



