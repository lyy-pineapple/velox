/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "velox/dwio/common/Statistics.h"
#include "velox/dwio/parquet/reader/SemanticVersion.h"
#include "velox/dwio/parquet/thrift/ParquetThriftTypes.h"

namespace facebook::velox::parquet {

struct ParquetStatsContext : dwio::common::StatsContext {
 public:
  ParquetStatsContext() = default;

  ParquetStatsContext(std::optional<SemanticVersion> version)
      : parquetVersion(std::move(version)) {}

  bool shouldIgnoreStatistics(thrift::Type::type type) const {
    if (!parquetVersion.has_value()) {
      return true;
    }
    return parquetVersion->shouldIgnoreStatistics(type);
  }

 private:
  std::optional<SemanticVersion> parquetVersion;
};

} // namespace facebook::velox::parquet
