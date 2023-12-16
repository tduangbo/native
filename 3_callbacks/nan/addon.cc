// #include <nan.h>

// void RunCallback(const Nan::FunctionCallbackInfo<v8::Value>& info) {
//   v8::Local<v8::Function> cb = info[0].As<v8::Function>();
//   const unsigned argc = 1;
// bool isCodingFun = true;
//   double value = 100*100;
// //string greeting = "Hello";
//   v8::Local<v8::Value> argv[argc] = {Nan::New(isCodingFun)};
//   //  v8::Local<v8::Value> argv[argc] = {Nan::New("hello").ToLocalChecked()};
//   Nan::AsyncResource resource("nan:makeCallback");
//   resource.runInAsyncScope(Nan::GetCurrentContext()->Global(), cb, argc, argv);
// }

// void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
//   Nan::SetMethod(module, "exports", RunCallback);
// }

// NODE_MODULE(addon, Init)

//web version

// addon.cc
#include <node.h>

namespace demo {

using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Null;
using v8::Object;
using v8::String;
using v8::Value;

void RunCallback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = {
      String::NewFromUtf8(isolate,
                          "hello world").ToLocalChecked() };
  cb->Call(context, Null(isolate), argc, argv).ToLocalChecked();
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", RunCallback);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo
