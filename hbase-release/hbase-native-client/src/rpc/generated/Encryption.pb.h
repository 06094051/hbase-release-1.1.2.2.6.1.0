// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Encryption.proto

#ifndef PROTOBUF_Encryption_2eproto__INCLUDED
#define PROTOBUF_Encryption_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace hbase {
namespace pb {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Encryption_2eproto();
void protobuf_AssignDesc_Encryption_2eproto();
void protobuf_ShutdownFile_Encryption_2eproto();

class WrappedKey;

// ===================================================================

class WrappedKey : public ::google::protobuf::Message {
 public:
  WrappedKey();
  virtual ~WrappedKey();

  WrappedKey(const WrappedKey& from);

  inline WrappedKey& operator=(const WrappedKey& from) {
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
  static const WrappedKey& default_instance();

  void Swap(WrappedKey* other);

  // implements Message ----------------------------------------------

  WrappedKey* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const WrappedKey& from);
  void MergeFrom(const WrappedKey& from);
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

  // required string algorithm = 1;
  inline bool has_algorithm() const;
  inline void clear_algorithm();
  static const int kAlgorithmFieldNumber = 1;
  inline const ::std::string& algorithm() const;
  inline void set_algorithm(const ::std::string& value);
  inline void set_algorithm(const char* value);
  inline void set_algorithm(const char* value, size_t size);
  inline ::std::string* mutable_algorithm();
  inline ::std::string* release_algorithm();
  inline void set_allocated_algorithm(::std::string* algorithm);

  // required uint32 length = 2;
  inline bool has_length() const;
  inline void clear_length();
  static const int kLengthFieldNumber = 2;
  inline ::google::protobuf::uint32 length() const;
  inline void set_length(::google::protobuf::uint32 value);

  // required bytes data = 3;
  inline bool has_data() const;
  inline void clear_data();
  static const int kDataFieldNumber = 3;
  inline const ::std::string& data() const;
  inline void set_data(const ::std::string& value);
  inline void set_data(const char* value);
  inline void set_data(const void* value, size_t size);
  inline ::std::string* mutable_data();
  inline ::std::string* release_data();
  inline void set_allocated_data(::std::string* data);

  // optional bytes iv = 4;
  inline bool has_iv() const;
  inline void clear_iv();
  static const int kIvFieldNumber = 4;
  inline const ::std::string& iv() const;
  inline void set_iv(const ::std::string& value);
  inline void set_iv(const char* value);
  inline void set_iv(const void* value, size_t size);
  inline ::std::string* mutable_iv();
  inline ::std::string* release_iv();
  inline void set_allocated_iv(::std::string* iv);

  // optional bytes hash = 5;
  inline bool has_hash() const;
  inline void clear_hash();
  static const int kHashFieldNumber = 5;
  inline const ::std::string& hash() const;
  inline void set_hash(const ::std::string& value);
  inline void set_hash(const char* value);
  inline void set_hash(const void* value, size_t size);
  inline ::std::string* mutable_hash();
  inline ::std::string* release_hash();
  inline void set_allocated_hash(::std::string* hash);

  // @@protoc_insertion_point(class_scope:hbase.pb.WrappedKey)
 private:
  inline void set_has_algorithm();
  inline void clear_has_algorithm();
  inline void set_has_length();
  inline void clear_has_length();
  inline void set_has_data();
  inline void clear_has_data();
  inline void set_has_iv();
  inline void clear_has_iv();
  inline void set_has_hash();
  inline void clear_has_hash();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* algorithm_;
  ::std::string* data_;
  ::std::string* iv_;
  ::std::string* hash_;
  ::google::protobuf::uint32 length_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_Encryption_2eproto();
  friend void protobuf_AssignDesc_Encryption_2eproto();
  friend void protobuf_ShutdownFile_Encryption_2eproto();

  void InitAsDefaultInstance();
  static WrappedKey* default_instance_;
};
// ===================================================================


// ===================================================================

// WrappedKey

// required string algorithm = 1;
inline bool WrappedKey::has_algorithm() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void WrappedKey::set_has_algorithm() {
  _has_bits_[0] |= 0x00000001u;
}
inline void WrappedKey::clear_has_algorithm() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void WrappedKey::clear_algorithm() {
  if (algorithm_ != &::google::protobuf::internal::kEmptyString) {
    algorithm_->clear();
  }
  clear_has_algorithm();
}
inline const ::std::string& WrappedKey::algorithm() const {
  return *algorithm_;
}
inline void WrappedKey::set_algorithm(const ::std::string& value) {
  set_has_algorithm();
  if (algorithm_ == &::google::protobuf::internal::kEmptyString) {
    algorithm_ = new ::std::string;
  }
  algorithm_->assign(value);
}
inline void WrappedKey::set_algorithm(const char* value) {
  set_has_algorithm();
  if (algorithm_ == &::google::protobuf::internal::kEmptyString) {
    algorithm_ = new ::std::string;
  }
  algorithm_->assign(value);
}
inline void WrappedKey::set_algorithm(const char* value, size_t size) {
  set_has_algorithm();
  if (algorithm_ == &::google::protobuf::internal::kEmptyString) {
    algorithm_ = new ::std::string;
  }
  algorithm_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* WrappedKey::mutable_algorithm() {
  set_has_algorithm();
  if (algorithm_ == &::google::protobuf::internal::kEmptyString) {
    algorithm_ = new ::std::string;
  }
  return algorithm_;
}
inline ::std::string* WrappedKey::release_algorithm() {
  clear_has_algorithm();
  if (algorithm_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = algorithm_;
    algorithm_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void WrappedKey::set_allocated_algorithm(::std::string* algorithm) {
  if (algorithm_ != &::google::protobuf::internal::kEmptyString) {
    delete algorithm_;
  }
  if (algorithm) {
    set_has_algorithm();
    algorithm_ = algorithm;
  } else {
    clear_has_algorithm();
    algorithm_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required uint32 length = 2;
inline bool WrappedKey::has_length() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void WrappedKey::set_has_length() {
  _has_bits_[0] |= 0x00000002u;
}
inline void WrappedKey::clear_has_length() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void WrappedKey::clear_length() {
  length_ = 0u;
  clear_has_length();
}
inline ::google::protobuf::uint32 WrappedKey::length() const {
  return length_;
}
inline void WrappedKey::set_length(::google::protobuf::uint32 value) {
  set_has_length();
  length_ = value;
}

// required bytes data = 3;
inline bool WrappedKey::has_data() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void WrappedKey::set_has_data() {
  _has_bits_[0] |= 0x00000004u;
}
inline void WrappedKey::clear_has_data() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void WrappedKey::clear_data() {
  if (data_ != &::google::protobuf::internal::kEmptyString) {
    data_->clear();
  }
  clear_has_data();
}
inline const ::std::string& WrappedKey::data() const {
  return *data_;
}
inline void WrappedKey::set_data(const ::std::string& value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  data_->assign(value);
}
inline void WrappedKey::set_data(const char* value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  data_->assign(value);
}
inline void WrappedKey::set_data(const void* value, size_t size) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  data_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* WrappedKey::mutable_data() {
  set_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    data_ = new ::std::string;
  }
  return data_;
}
inline ::std::string* WrappedKey::release_data() {
  clear_has_data();
  if (data_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = data_;
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void WrappedKey::set_allocated_data(::std::string* data) {
  if (data_ != &::google::protobuf::internal::kEmptyString) {
    delete data_;
  }
  if (data) {
    set_has_data();
    data_ = data;
  } else {
    clear_has_data();
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional bytes iv = 4;
inline bool WrappedKey::has_iv() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void WrappedKey::set_has_iv() {
  _has_bits_[0] |= 0x00000008u;
}
inline void WrappedKey::clear_has_iv() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void WrappedKey::clear_iv() {
  if (iv_ != &::google::protobuf::internal::kEmptyString) {
    iv_->clear();
  }
  clear_has_iv();
}
inline const ::std::string& WrappedKey::iv() const {
  return *iv_;
}
inline void WrappedKey::set_iv(const ::std::string& value) {
  set_has_iv();
  if (iv_ == &::google::protobuf::internal::kEmptyString) {
    iv_ = new ::std::string;
  }
  iv_->assign(value);
}
inline void WrappedKey::set_iv(const char* value) {
  set_has_iv();
  if (iv_ == &::google::protobuf::internal::kEmptyString) {
    iv_ = new ::std::string;
  }
  iv_->assign(value);
}
inline void WrappedKey::set_iv(const void* value, size_t size) {
  set_has_iv();
  if (iv_ == &::google::protobuf::internal::kEmptyString) {
    iv_ = new ::std::string;
  }
  iv_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* WrappedKey::mutable_iv() {
  set_has_iv();
  if (iv_ == &::google::protobuf::internal::kEmptyString) {
    iv_ = new ::std::string;
  }
  return iv_;
}
inline ::std::string* WrappedKey::release_iv() {
  clear_has_iv();
  if (iv_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = iv_;
    iv_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void WrappedKey::set_allocated_iv(::std::string* iv) {
  if (iv_ != &::google::protobuf::internal::kEmptyString) {
    delete iv_;
  }
  if (iv) {
    set_has_iv();
    iv_ = iv;
  } else {
    clear_has_iv();
    iv_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional bytes hash = 5;
inline bool WrappedKey::has_hash() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void WrappedKey::set_has_hash() {
  _has_bits_[0] |= 0x00000010u;
}
inline void WrappedKey::clear_has_hash() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void WrappedKey::clear_hash() {
  if (hash_ != &::google::protobuf::internal::kEmptyString) {
    hash_->clear();
  }
  clear_has_hash();
}
inline const ::std::string& WrappedKey::hash() const {
  return *hash_;
}
inline void WrappedKey::set_hash(const ::std::string& value) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(value);
}
inline void WrappedKey::set_hash(const char* value) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(value);
}
inline void WrappedKey::set_hash(const void* value, size_t size) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* WrappedKey::mutable_hash() {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  return hash_;
}
inline ::std::string* WrappedKey::release_hash() {
  clear_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = hash_;
    hash_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void WrappedKey::set_allocated_hash(::std::string* hash) {
  if (hash_ != &::google::protobuf::internal::kEmptyString) {
    delete hash_;
  }
  if (hash) {
    set_has_hash();
    hash_ = hash;
  } else {
    clear_has_hash();
    hash_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace hbase

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Encryption_2eproto__INCLUDED
