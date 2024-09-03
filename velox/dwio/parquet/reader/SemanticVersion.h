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

#include "velox/dwio/parquet/thrift/ParquetThriftTypes.h"

#include <string>
#include <optional>
#include <re2/re2.h>

namespace facebook::velox::parquet {

class SemanticVersion {
 public:
  SemanticVersion();

  SemanticVersion(int major, int minor, int patch);

  SemanticVersion(std::string application,int major, int minor, int patch);

  SemanticVersion(const SemanticVersion& other);

  static std::optional<SemanticVersion> parse(const std::string& input);

  bool shouldIgnoreStatistics(thrift::Type::type type);

  std::string toString() const;

  bool operator==(const SemanticVersion& other) const;

  bool operator<(const SemanticVersion& other) const;

 private:
  std::string application;
  int majorVersion;
  int minorVersion;
  int patchVersion;

  static const re2::RE2 pattern;
};

} // namespace facebook::velox::parquet

