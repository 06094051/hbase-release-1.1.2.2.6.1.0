// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Cell.proto

#ifndef PROTOBUF_Cell_2eproto__INCLUDED
#define PROTOBUF_Cell_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace hbase {
namespace pb {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Cell_2eproto();
void protobuf_AssignDesc_Cell_2eproto();
void protobuf_ShutdownFile_Cell_2eproto();

class Cell;
class KeyValue;

enum CellType {
  MINIMUM = 0,
  PUT = 4,
  DELETE = 8,
  DELETE_COLUMN = 12,
  DELETE_FAMILY = 14,
  MAXIMUM = 255
};
bool CellType_IsValid(int value);
const CellType CellType_MIN = MINIMUM;
const CellType CellType_MAX = MAXIMUM;
const int CellType_ARRAYSIZE = CellType_MAX + 1;

const ::google::protobuf::EnumDescriptor* CellType_descriptor();
inline const ::std::string& CellType_Name(CellType value) {
  return ::google::protobuf::internal::NameOfEnum(
    CellType_descriptor(), value);
}
inline bool CellType_Parse(
    const ::std::string& name, CellType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CellType>(
    CellType_descriptor(), name, value);
}
// ===================================================================

class Cell : public ::google::protobuf::Message {
 public:
  Cell();
  virtual ~Cell();

  Cell(const Cell& from);

  inline Cell& operator=(const Cell& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Cell& default_instance();

  void Swap(Cell* other);

  // implements Message ----------------------------------------------

  Cell* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Cell& from);
  void MergeFrom(const Cell& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes row = 1;
  inline bool has_row() const;
  inline void clear_row();
  static const int kRowFieldNumber = 1;
  inline const ::std::string& row() const;
  inline void set_row(const ::std::string& value);
  inline void set_row(const char* value);
  inline void set_row(const void* value, size_t size);
  inline ::std::string* mutable_row();
  inline ::std::string* release_row();
  inline void set_allocated_row(::std::string* row);

  // optional bytes family = 2;
  inline bool has_family() const;
  inline void clear_family();
  static const int kFamilyFieldNumber = 2;
  inline const ::std::string& family() const;
  inline void set_family(const ::std::string& value);
  inline void set_family(const char* value);
  inline void set_family(const void* value, size_t size);
  inline ::std::string* mutable_family();
  inline ::std::string* release_family();
  inline void set_allocated_family(::std::string* family);

  // optional bytes qualifier = 3;
  inline bool has_qualifier() const;
  inline void clear_qualifier();
  static const int kQualifierFieldNumber = 3;
  inline const ::std::string& qualifier() const;
  inline void set_qualifier(const ::std::string& value);
  inline void set_qualifier(const char* value);
  inline void set_qualifier(const void* value, size_t size);
  inline ::std::string* mutable_qualifier();
  inline ::std::string* release_qualifier();
  inline void set_allocated_qualifier(::std::string* qualifier);

  // optional uint64 timestamp = 4;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 4;
  inline ::google::protobuf::uint64 timestamp() const;
  inline void set_timestamp(::google::protobuf::uint64 value);

  // optional .hbase.pb.CellType cell_type = 5;
  inline bool has_cell_type() const;
  inline void clear_cell_type();
  static const int kCellTypeFieldNumber = 5;
  inline ::hbase::pb::CellType cell_type() const;
  inline void set_cell_type(::hbase::pb::CellType value);

  // optional bytes value = 6;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 6;
  inline const ::std::string& value() const;
  inline void set_value(const ::std::string& value);
  inline void set_value(const char* value);
  inline void set_value(const void* value, size_t size);
  inline ::std::string* mutable_value();
  inline ::std::string* release_value();
  inline void set_allocated_value(::std::string* value);

  // optional bytes tags = 7;
  inline bool has_tags() const;
  inline void clear_tags();
  static const int kTagsFieldNumber = 7;
  inline const ::std::string& tags() const;
  inline void set_tags(const ::std::string& value);
  inline void set_tags(const char* value);
  inline void set_tags(const void* value, size_t size);
  inline ::std::string* mutable_tags();
  inline ::std::string* release_tags();
  inline void set_allocated_tags(::std::string* tags);

  // @@protoc_insertion_point(class_scope:hbase.pb.Cell)
 private:
  inline void set_has_row();
  inline void clear_has_row();
  inline void set_has_family();
  inline void clear_has_family();
  inline void set_has_qualifier();
  inline void clear_has_qualifier();
  inline void set_has_timestamp();
  inline void clear_has_timestamp();
  inline void set_has_cell_type();
  inline void clear_has_cell_type();
  inline void set_has_value();
  inline void clear_has_value();
  inline void set_has_tags();
  inline void clear_has_tags();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* row_;
  ::std::string* family_;
  ::std::string* qualifier_;
  ::google::protobuf::uint64 timestamp_;
  ::std::string* value_;
  ::std::string* tags_;
  int cell_type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_Cell_2eproto();
  friend void protobuf_AssignDesc_Cell_2eproto();
  friend void protobuf_ShutdownFile_Cell_2eproto();

  void InitAsDefaultInstance();
  static Cell* default_instance_;
};
// -------------------------------------------------------------------

class KeyValue : public ::google::protobuf::Message {
 public:
  KeyValue();
  virtual ~KeyValue();

  KeyValue(const KeyValue& from);

  inline KeyValue& operator=(const KeyValue& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const KeyValue& default_instance();

  void Swap(KeyValue* other);

  // implements Message ----------------------------------------------

  KeyValue* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const KeyValue& from);
  void MergeFrom(const KeyValue& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bytes row = 1;
  inline bool has_row() const;
  inline void clear_row();
  static const int kRowFieldNumber = 1;
  inline const ::std::string& row() const;
  inline void set_row(const ::std::string& value);
  inline void set_row(const char* value);
  inline void set_row(const void* value, size_t size);
  inline ::std::string* mutable_row();
  inline ::std::string* release_row();
  inline void set_allocated_row(::std::string* row);

  // required bytes family = 2;
  inline bool has_family() const;
  inline void clear_family();
  static const int kFamilyFieldNumber = 2;
  inline const ::std::string& family() const;
  inline void set_family(const ::std::string& value);
  inline void set_family(const char* value);
  inline void set_family(const void* value, size_t size);
  inline ::std::string* mutable_family();
  inline ::std::string* release_family();
  inline void set_allocated_family(::std::string* family);

  // required bytes qualifier = 3;
  inline bool has_qualifier() const;
  inline void clear_qualifier();
  static const int kQualifierFieldNumber = 3;
  inline const ::std::string& qualifier() const;
  inline void set_qualifier(const ::std::string& value);
  inline void set_qualifier(const char* value);
  inline void set_qualifier(const void* value, size_t size);
  inline ::std::string* mutable_qualifier();
  inline ::std::string* release_qualifier();
  inline void set_allocated_qualifier(::std::string* qualifier);

  // optional uint64 timestamp = 4;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 4;
  inline ::google::protobuf::uint64 timestamp() const;
  inline void set_timestamp(::google::protobuf::uint64 value);

  // optional .hbase.pb.CellType key_type = 5;
  inline bool has_key_type() const;
  inline void clear_key_type();
  static const int kKeyTypeFieldNumber = 5;
  inline ::hbase::pb::CellType key_type() const;
  inline void set_key_type(::hbase::pb::CellType value);

  // optional bytes value = 6;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 6;
  inline const ::std::string& value() const;
  inline void set_value(const ::std::string& value);
  inline void set_value(const char* value);
  inline void set_value(const void* value, size_t size);
  inline ::std::string* mutable_value();
  inline ::std::string* release_value();
  inline void set_allocated_value(::std::string* value);

  // optional bytes tags = 7;
  inline bool has_tags() const;
  inline void clear_tags();
  static const int kTagsFieldNumber = 7;
  inline const ::std::string& tags() const;
  inline void set_tags(const ::std::string& value);
  inline void set_tags(const char* value);
  inline void set_tags(const void* value, size_t size);
  inline ::std::string* mutable_tags();
  inline ::std::string* release_tags();
  inline void set_allocated_tags(::std::string* tags);

  // @@protoc_insertion_point(class_scope:hbase.pb.KeyValue)
 private:
  inline void set_has_row();
  inline void clear_has_row();
  inline void set_has_family();
  inline void clear_has_family();
  inline void set_has_qualifier();
  inline void clear_has_qualifier();
  inline void set_has_timestamp();
  inline void clear_has_timestamp();
  inline void set_has_key_type();
  inline void clear_has_key_type();
  inline void set_has_value();
  inline void clear_has_value();
  inline void set_has_tags();
  inline void clear_has_tags();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* row_;
  ::std::string* family_;
  ::std::string* qualifier_;
  ::google::protobuf::uint64 timestamp_;
  ::std::string* value_;
  ::std::string* tags_;
  int key_type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_Cell_2eproto();
  friend void protobuf_AssignDesc_Cell_2eproto();
  friend void protobuf_ShutdownFile_Cell_2eproto();

  void InitAsDefaultInstance();
  static KeyValue* default_instance_;
};
// ===================================================================


// ===================================================================

// Cell

// optional bytes row = 1;
inline bool Cell::has_row() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Cell::set_has_row() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Cell::clear_has_row() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Cell::clear_row() {
  if (row_ != &::google::protobuf::internal::kEmptyString) {
    row_->clear();
  }
  clear_has_row();
}
inline const ::std::string& Cell::row() const {
  return *row_;
}
inline void Cell::set_row(const ::std::string& value) {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  row_->assign(value);
}
inline void Cell::set_row(const char* value) {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  row_->assign(value);
}
inline void Cell::set_row(const void* value, size_t size) {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  row_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Cell::mutable_row() {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  return row_;
}
inline ::std::string* Cell::release_row() {
  clear_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = row_;
    row_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Cell::set_allocated_row(::std::string* row) {
  if (row_ != &::google::protobuf::internal::kEmptyString) {
    delete row_;
  }
  if (row) {
    set_has_row();
    row_ = row;
  } else {
    clear_has_row();
    row_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional bytes family = 2;
inline bool Cell::has_family() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Cell::set_has_family() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Cell::clear_has_family() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Cell::clear_family() {
  if (family_ != &::google::protobuf::internal::kEmptyString) {
    family_->clear();
  }
  clear_has_family();
}
inline const ::std::string& Cell::family() const {
  return *family_;
}
inline void Cell::set_family(const ::std::string& value) {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  family_->assign(value);
}
inline void Cell::set_family(const char* value) {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  family_->assign(value);
}
inline void Cell::set_family(const void* value, size_t size) {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  family_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Cell::mutable_family() {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  return family_;
}
inline ::std::string* Cell::release_family() {
  clear_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = family_;
    family_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Cell::set_allocated_family(::std::string* family) {
  if (family_ != &::google::protobuf::internal::kEmptyString) {
    delete family_;
  }
  if (family) {
    set_has_family();
    family_ = family;
  } else {
    clear_has_family();
    family_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional bytes qualifier = 3;
inline bool Cell::has_qualifier() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Cell::set_has_qualifier() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Cell::clear_has_qualifier() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Cell::clear_qualifier() {
  if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
    qualifier_->clear();
  }
  clear_has_qualifier();
}
inline const ::std::string& Cell::qualifier() const {
  return *qualifier_;
}
inline void Cell::set_qualifier(const ::std::string& value) {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  qualifier_->assign(value);
}
inline void Cell::set_qualifier(const char* value) {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  qualifier_->assign(value);
}
inline void Cell::set_qualifier(const void* value, size_t size) {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  qualifier_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Cell::mutable_qualifier() {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  return qualifier_;
}
inline ::std::string* Cell::release_qualifier() {
  clear_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = qualifier_;
    qualifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Cell::set_allocated_qualifier(::std::string* qualifier) {
  if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
    delete qualifier_;
  }
  if (qualifier) {
    set_has_qualifier();
    qualifier_ = qualifier;
  } else {
    clear_has_qualifier();
    qualifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional uint64 timestamp = 4;
inline bool Cell::has_timestamp() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Cell::set_has_timestamp() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Cell::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Cell::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_timestamp();
}
inline ::google::protobuf::uint64 Cell::timestamp() const {
  return timestamp_;
}
inline void Cell::set_timestamp(::google::protobuf::uint64 value) {
  set_has_timestamp();
  timestamp_ = value;
}

// optional .hbase.pb.CellType cell_type = 5;
inline bool Cell::has_cell_type() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Cell::set_has_cell_type() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Cell::clear_has_cell_type() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Cell::clear_cell_type() {
  cell_type_ = 0;
  clear_has_cell_type();
}
inline ::hbase::pb::CellType Cell::cell_type() const {
  return static_cast< ::hbase::pb::CellType >(cell_type_);
}
inline void Cell::set_cell_type(::hbase::pb::CellType value) {
  assert(::hbase::pb::CellType_IsValid(value));
  set_has_cell_type();
  cell_type_ = value;
}

// optional bytes value = 6;
inline bool Cell::has_value() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Cell::set_has_value() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Cell::clear_has_value() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Cell::clear_value() {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    value_->clear();
  }
  clear_has_value();
}
inline const ::std::string& Cell::value() const {
  return *value_;
}
inline void Cell::set_value(const ::std::string& value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void Cell::set_value(const char* value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void Cell::set_value(const void* value, size_t size) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Cell::mutable_value() {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  return value_;
}
inline ::std::string* Cell::release_value() {
  clear_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = value_;
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Cell::set_allocated_value(::std::string* value) {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    delete value_;
  }
  if (value) {
    set_has_value();
    value_ = value;
  } else {
    clear_has_value();
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional bytes tags = 7;
inline bool Cell::has_tags() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Cell::set_has_tags() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Cell::clear_has_tags() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Cell::clear_tags() {
  if (tags_ != &::google::protobuf::internal::kEmptyString) {
    tags_->clear();
  }
  clear_has_tags();
}
inline const ::std::string& Cell::tags() const {
  return *tags_;
}
inline void Cell::set_tags(const ::std::string& value) {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  tags_->assign(value);
}
inline void Cell::set_tags(const char* value) {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  tags_->assign(value);
}
inline void Cell::set_tags(const void* value, size_t size) {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  tags_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Cell::mutable_tags() {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  return tags_;
}
inline ::std::string* Cell::release_tags() {
  clear_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = tags_;
    tags_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Cell::set_allocated_tags(::std::string* tags) {
  if (tags_ != &::google::protobuf::internal::kEmptyString) {
    delete tags_;
  }
  if (tags) {
    set_has_tags();
    tags_ = tags;
  } else {
    clear_has_tags();
    tags_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// KeyValue

// required bytes row = 1;
inline bool KeyValue::has_row() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void KeyValue::set_has_row() {
  _has_bits_[0] |= 0x00000001u;
}
inline void KeyValue::clear_has_row() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void KeyValue::clear_row() {
  if (row_ != &::google::protobuf::internal::kEmptyString) {
    row_->clear();
  }
  clear_has_row();
}
inline const ::std::string& KeyValue::row() const {
  return *row_;
}
inline void KeyValue::set_row(const ::std::string& value) {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  row_->assign(value);
}
inline void KeyValue::set_row(const char* value) {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  row_->assign(value);
}
inline void KeyValue::set_row(const void* value, size_t size) {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  row_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* KeyValue::mutable_row() {
  set_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    row_ = new ::std::string;
  }
  return row_;
}
inline ::std::string* KeyValue::release_row() {
  clear_has_row();
  if (row_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = row_;
    row_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void KeyValue::set_allocated_row(::std::string* row) {
  if (row_ != &::google::protobuf::internal::kEmptyString) {
    delete row_;
  }
  if (row) {
    set_has_row();
    row_ = row;
  } else {
    clear_has_row();
    row_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bytes family = 2;
inline bool KeyValue::has_family() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void KeyValue::set_has_family() {
  _has_bits_[0] |= 0x00000002u;
}
inline void KeyValue::clear_has_family() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void KeyValue::clear_family() {
  if (family_ != &::google::protobuf::internal::kEmptyString) {
    family_->clear();
  }
  clear_has_family();
}
inline const ::std::string& KeyValue::family() const {
  return *family_;
}
inline void KeyValue::set_family(const ::std::string& value) {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  family_->assign(value);
}
inline void KeyValue::set_family(const char* value) {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  family_->assign(value);
}
inline void KeyValue::set_family(const void* value, size_t size) {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  family_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* KeyValue::mutable_family() {
  set_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    family_ = new ::std::string;
  }
  return family_;
}
inline ::std::string* KeyValue::release_family() {
  clear_has_family();
  if (family_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = family_;
    family_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void KeyValue::set_allocated_family(::std::string* family) {
  if (family_ != &::google::protobuf::internal::kEmptyString) {
    delete family_;
  }
  if (family) {
    set_has_family();
    family_ = family;
  } else {
    clear_has_family();
    family_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bytes qualifier = 3;
inline bool KeyValue::has_qualifier() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void KeyValue::set_has_qualifier() {
  _has_bits_[0] |= 0x00000004u;
}
inline void KeyValue::clear_has_qualifier() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void KeyValue::clear_qualifier() {
  if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
    qualifier_->clear();
  }
  clear_has_qualifier();
}
inline const ::std::string& KeyValue::qualifier() const {
  return *qualifier_;
}
inline void KeyValue::set_qualifier(const ::std::string& value) {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  qualifier_->assign(value);
}
inline void KeyValue::set_qualifier(const char* value) {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  qualifier_->assign(value);
}
inline void KeyValue::set_qualifier(const void* value, size_t size) {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  qualifier_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* KeyValue::mutable_qualifier() {
  set_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    qualifier_ = new ::std::string;
  }
  return qualifier_;
}
inline ::std::string* KeyValue::release_qualifier() {
  clear_has_qualifier();
  if (qualifier_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = qualifier_;
    qualifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void KeyValue::set_allocated_qualifier(::std::string* qualifier) {
  if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
    delete qualifier_;
  }
  if (qualifier) {
    set_has_qualifier();
    qualifier_ = qualifier;
  } else {
    clear_has_qualifier();
    qualifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional uint64 timestamp = 4;
inline bool KeyValue::has_timestamp() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void KeyValue::set_has_timestamp() {
  _has_bits_[0] |= 0x00000008u;
}
inline void KeyValue::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void KeyValue::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_timestamp();
}
inline ::google::protobuf::uint64 KeyValue::timestamp() const {
  return timestamp_;
}
inline void KeyValue::set_timestamp(::google::protobuf::uint64 value) {
  set_has_timestamp();
  timestamp_ = value;
}

// optional .hbase.pb.CellType key_type = 5;
inline bool KeyValue::has_key_type() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void KeyValue::set_has_key_type() {
  _has_bits_[0] |= 0x00000010u;
}
inline void KeyValue::clear_has_key_type() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void KeyValue::clear_key_type() {
  key_type_ = 0;
  clear_has_key_type();
}
inline ::hbase::pb::CellType KeyValue::key_type() const {
  return static_cast< ::hbase::pb::CellType >(key_type_);
}
inline void KeyValue::set_key_type(::hbase::pb::CellType value) {
  assert(::hbase::pb::CellType_IsValid(value));
  set_has_key_type();
  key_type_ = value;
}

// optional bytes value = 6;
inline bool KeyValue::has_value() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void KeyValue::set_has_value() {
  _has_bits_[0] |= 0x00000020u;
}
inline void KeyValue::clear_has_value() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void KeyValue::clear_value() {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    value_->clear();
  }
  clear_has_value();
}
inline const ::std::string& KeyValue::value() const {
  return *value_;
}
inline void KeyValue::set_value(const ::std::string& value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void KeyValue::set_value(const char* value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void KeyValue::set_value(const void* value, size_t size) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* KeyValue::mutable_value() {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  return value_;
}
inline ::std::string* KeyValue::release_value() {
  clear_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = value_;
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void KeyValue::set_allocated_value(::std::string* value) {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    delete value_;
  }
  if (value) {
    set_has_value();
    value_ = value;
  } else {
    clear_has_value();
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional bytes tags = 7;
inline bool KeyValue::has_tags() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void KeyValue::set_has_tags() {
  _has_bits_[0] |= 0x00000040u;
}
inline void KeyValue::clear_has_tags() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void KeyValue::clear_tags() {
  if (tags_ != &::google::protobuf::internal::kEmptyString) {
    tags_->clear();
  }
  clear_has_tags();
}
inline const ::std::string& KeyValue::tags() const {
  return *tags_;
}
inline void KeyValue::set_tags(const ::std::string& value) {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  tags_->assign(value);
}
inline void KeyValue::set_tags(const char* value) {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  tags_->assign(value);
}
inline void KeyValue::set_tags(const void* value, size_t size) {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  tags_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* KeyValue::mutable_tags() {
  set_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    tags_ = new ::std::string;
  }
  return tags_;
}
inline ::std::string* KeyValue::release_tags() {
  clear_has_tags();
  if (tags_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = tags_;
    tags_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void KeyValue::set_allocated_tags(::std::string* tags) {
  if (tags_ != &::google::protobuf::internal::kEmptyString) {
    delete tags_;
  }
  if (tags) {
    set_has_tags();
    tags_ = tags;
  } else {
    clear_has_tags();
    tags_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace hbase

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::hbase::pb::CellType>() {
  return ::hbase::pb::CellType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Cell_2eproto__INCLUDED
