// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MapReduce.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MapReduce.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace hbase {
namespace pb {

namespace {

const ::google::protobuf::Descriptor* ScanMetrics_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ScanMetrics_reflection_ = NULL;
const ::google::protobuf::Descriptor* TableSnapshotRegionSplit_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TableSnapshotRegionSplit_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MapReduce_2eproto() {
  protobuf_AddDesc_MapReduce_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MapReduce.proto");
  GOOGLE_CHECK(file != NULL);
  ScanMetrics_descriptor_ = file->message_type(0);
  static const int ScanMetrics_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ScanMetrics, metrics_),
  };
  ScanMetrics_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ScanMetrics_descriptor_,
      ScanMetrics::default_instance_,
      ScanMetrics_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ScanMetrics, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ScanMetrics, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ScanMetrics));
  TableSnapshotRegionSplit_descriptor_ = file->message_type(1);
  static const int TableSnapshotRegionSplit_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TableSnapshotRegionSplit, locations_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TableSnapshotRegionSplit, table_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TableSnapshotRegionSplit, region_),
  };
  TableSnapshotRegionSplit_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TableSnapshotRegionSplit_descriptor_,
      TableSnapshotRegionSplit::default_instance_,
      TableSnapshotRegionSplit_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TableSnapshotRegionSplit, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TableSnapshotRegionSplit, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TableSnapshotRegionSplit));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MapReduce_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ScanMetrics_descriptor_, &ScanMetrics::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TableSnapshotRegionSplit_descriptor_, &TableSnapshotRegionSplit::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MapReduce_2eproto() {
  delete ScanMetrics::default_instance_;
  delete ScanMetrics_reflection_;
  delete TableSnapshotRegionSplit::default_instance_;
  delete TableSnapshotRegionSplit_reflection_;
}

void protobuf_AddDesc_MapReduce_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::hbase::pb::protobuf_AddDesc_HBase_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017MapReduce.proto\022\010hbase.pb\032\013HBase.proto"
    "\"7\n\013ScanMetrics\022(\n\007metrics\030\001 \003(\0132\027.hbase"
    ".pb.NameInt64Pair\"y\n\030TableSnapshotRegion"
    "Split\022\021\n\tlocations\030\002 \003(\t\022$\n\005table\030\003 \001(\0132"
    "\025.hbase.pb.TableSchema\022$\n\006region\030\004 \001(\0132\024"
    ".hbase.pb.RegionInfoBB\n*org.apache.hadoo"
    "p.hbase.protobuf.generatedB\017MapReducePro"
    "tosH\001\240\001\001", 288);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MapReduce.proto", &protobuf_RegisterTypes);
  ScanMetrics::default_instance_ = new ScanMetrics();
  TableSnapshotRegionSplit::default_instance_ = new TableSnapshotRegionSplit();
  ScanMetrics::default_instance_->InitAsDefaultInstance();
  TableSnapshotRegionSplit::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MapReduce_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MapReduce_2eproto {
  StaticDescriptorInitializer_MapReduce_2eproto() {
    protobuf_AddDesc_MapReduce_2eproto();
  }
} static_descriptor_initializer_MapReduce_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ScanMetrics::kMetricsFieldNumber;
#endif  // !_MSC_VER

ScanMetrics::ScanMetrics()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ScanMetrics::InitAsDefaultInstance() {
}

ScanMetrics::ScanMetrics(const ScanMetrics& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ScanMetrics::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ScanMetrics::~ScanMetrics() {
  SharedDtor();
}

void ScanMetrics::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ScanMetrics::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ScanMetrics::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ScanMetrics_descriptor_;
}

const ScanMetrics& ScanMetrics::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MapReduce_2eproto();
  return *default_instance_;
}

ScanMetrics* ScanMetrics::default_instance_ = NULL;

ScanMetrics* ScanMetrics::New() const {
  return new ScanMetrics;
}

void ScanMetrics::Clear() {
  metrics_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ScanMetrics::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .hbase.pb.NameInt64Pair metrics = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_metrics:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_metrics()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_metrics;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ScanMetrics::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .hbase.pb.NameInt64Pair metrics = 1;
  for (int i = 0; i < this->metrics_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->metrics(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ScanMetrics::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .hbase.pb.NameInt64Pair metrics = 1;
  for (int i = 0; i < this->metrics_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->metrics(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ScanMetrics::ByteSize() const {
  int total_size = 0;

  // repeated .hbase.pb.NameInt64Pair metrics = 1;
  total_size += 1 * this->metrics_size();
  for (int i = 0; i < this->metrics_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->metrics(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ScanMetrics::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ScanMetrics* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ScanMetrics*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ScanMetrics::MergeFrom(const ScanMetrics& from) {
  GOOGLE_CHECK_NE(&from, this);
  metrics_.MergeFrom(from.metrics_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ScanMetrics::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScanMetrics::CopyFrom(const ScanMetrics& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScanMetrics::IsInitialized() const {

  return true;
}

void ScanMetrics::Swap(ScanMetrics* other) {
  if (other != this) {
    metrics_.Swap(&other->metrics_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ScanMetrics::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ScanMetrics_descriptor_;
  metadata.reflection = ScanMetrics_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int TableSnapshotRegionSplit::kLocationsFieldNumber;
const int TableSnapshotRegionSplit::kTableFieldNumber;
const int TableSnapshotRegionSplit::kRegionFieldNumber;
#endif  // !_MSC_VER

TableSnapshotRegionSplit::TableSnapshotRegionSplit()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void TableSnapshotRegionSplit::InitAsDefaultInstance() {
  table_ = const_cast< ::hbase::pb::TableSchema*>(&::hbase::pb::TableSchema::default_instance());
  region_ = const_cast< ::hbase::pb::RegionInfo*>(&::hbase::pb::RegionInfo::default_instance());
}

TableSnapshotRegionSplit::TableSnapshotRegionSplit(const TableSnapshotRegionSplit& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void TableSnapshotRegionSplit::SharedCtor() {
  _cached_size_ = 0;
  table_ = NULL;
  region_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TableSnapshotRegionSplit::~TableSnapshotRegionSplit() {
  SharedDtor();
}

void TableSnapshotRegionSplit::SharedDtor() {
  if (this != default_instance_) {
    delete table_;
    delete region_;
  }
}

void TableSnapshotRegionSplit::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TableSnapshotRegionSplit::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TableSnapshotRegionSplit_descriptor_;
}

const TableSnapshotRegionSplit& TableSnapshotRegionSplit::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MapReduce_2eproto();
  return *default_instance_;
}

TableSnapshotRegionSplit* TableSnapshotRegionSplit::default_instance_ = NULL;

TableSnapshotRegionSplit* TableSnapshotRegionSplit::New() const {
  return new TableSnapshotRegionSplit;
}

void TableSnapshotRegionSplit::Clear() {
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (has_table()) {
      if (table_ != NULL) table_->::hbase::pb::TableSchema::Clear();
    }
    if (has_region()) {
      if (region_ != NULL) region_->::hbase::pb::RegionInfo::Clear();
    }
  }
  locations_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TableSnapshotRegionSplit::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated string locations = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_locations:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_locations()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->locations(this->locations_size() - 1).data(),
            this->locations(this->locations_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_locations;
        if (input->ExpectTag(26)) goto parse_table;
        break;
      }

      // optional .hbase.pb.TableSchema table = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_table:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_table()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_region;
        break;
      }

      // optional .hbase.pb.RegionInfo region = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_region:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_region()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void TableSnapshotRegionSplit::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated string locations = 2;
  for (int i = 0; i < this->locations_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->locations(i).data(), this->locations(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->locations(i), output);
  }

  // optional .hbase.pb.TableSchema table = 3;
  if (has_table()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->table(), output);
  }

  // optional .hbase.pb.RegionInfo region = 4;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->region(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* TableSnapshotRegionSplit::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated string locations = 2;
  for (int i = 0; i < this->locations_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->locations(i).data(), this->locations(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->locations(i), target);
  }

  // optional .hbase.pb.TableSchema table = 3;
  if (has_table()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->table(), target);
  }

  // optional .hbase.pb.RegionInfo region = 4;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->region(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int TableSnapshotRegionSplit::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional .hbase.pb.TableSchema table = 3;
    if (has_table()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->table());
    }

    // optional .hbase.pb.RegionInfo region = 4;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->region());
    }

  }
  // repeated string locations = 2;
  total_size += 1 * this->locations_size();
  for (int i = 0; i < this->locations_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->locations(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TableSnapshotRegionSplit::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TableSnapshotRegionSplit* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TableSnapshotRegionSplit*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TableSnapshotRegionSplit::MergeFrom(const TableSnapshotRegionSplit& from) {
  GOOGLE_CHECK_NE(&from, this);
  locations_.MergeFrom(from.locations_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_table()) {
      mutable_table()->::hbase::pb::TableSchema::MergeFrom(from.table());
    }
    if (from.has_region()) {
      mutable_region()->::hbase::pb::RegionInfo::MergeFrom(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TableSnapshotRegionSplit::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TableSnapshotRegionSplit::CopyFrom(const TableSnapshotRegionSplit& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TableSnapshotRegionSplit::IsInitialized() const {

  if (has_table()) {
    if (!this->table().IsInitialized()) return false;
  }
  if (has_region()) {
    if (!this->region().IsInitialized()) return false;
  }
  return true;
}

void TableSnapshotRegionSplit::Swap(TableSnapshotRegionSplit* other) {
  if (other != this) {
    locations_.Swap(&other->locations_);
    std::swap(table_, other->table_);
    std::swap(region_, other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TableSnapshotRegionSplit::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TableSnapshotRegionSplit_descriptor_;
  metadata.reflection = TableSnapshotRegionSplit_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace hbase

// @@protoc_insertion_point(global_scope)