/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_TRACE_PROCESSOR_IMPORTERS_PROTO_WINSCOPE_SURFACEFLINGER_LAYERS_PARSER_H_
#define SRC_TRACE_PROCESSOR_IMPORTERS_PROTO_WINSCOPE_SURFACEFLINGER_LAYERS_PARSER_H_

#include "src/trace_processor/tables/winscope_tables_py.h"
#include "src/trace_processor/types/trace_processor_context.h"
#include "src/trace_processor/util/descriptors.h"
#include "src/trace_processor/util/proto_to_args_parser.h"

namespace perfetto::trace_processor::winscope {

class SurfaceFlingerLayersParser {
 public:
  explicit SurfaceFlingerLayersParser(TraceProcessorContext*);
  void Parse(int64_t timestamp, protozero::ConstBytes);

 private:
  void ParseLayer(int64_t timestamp,
                  protozero::ConstBytes blob,
                  tables::SurfaceFlingerLayersSnapshotTable::Id);

  TraceProcessorContext* const context_;
  util::ProtoToArgsParser args_parser_;
};
}  // namespace perfetto::trace_processor::winscope

#endif  // SRC_TRACE_PROCESSOR_IMPORTERS_PROTO_WINSCOPE_SURFACEFLINGER_LAYERS_PARSER_H_
