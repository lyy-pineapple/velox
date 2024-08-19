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

#include <string>
#include <optional>
#include <re2/re2.h>

namespace facebook::velox::parquet {

class SemanticVersion {
 public:
  std::string application;
  int majorVersion;
  int minorVersion;
  int patchVersion;

  SemanticVersion();

  SemanticVersion(int major, int minor, int patch);

  static std::optional<SemanticVersion> parse(const std::string& input);

  static bool shouldIgnoreStatistics(const SemanticVersion& version);

  std::string toString() const;

  bool operator==(const SemanticVersion& other) const;

  bool operator<(const SemanticVersion& other) const;

  SemanticVersion(const SemanticVersion& other);

 private:
  static const re2::RE2 pattern;
};

} // namespace facebook::velox::parquet

