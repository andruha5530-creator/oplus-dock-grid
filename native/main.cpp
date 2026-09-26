#include <android/log.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include "zygisk.hpp"

#define TAG "OplusDockGrid"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

class OplusDockGrid : public zygisk::ModuleBase {
public:
    void onLoad(zygisk::Api* api, JNIEnv* env) override {
        api_ = api;
        env_ = env;
    }

    void postAppSpecialize(const zygisk::AppSpecializeArgs*) override {
        // Fail-closed: only inspect the launcher process; never patch ART yet.
        std::ifstream f("/proc/self/cmdline");
        std::string name;
        std::getline(f, name, '\0');
        if (name != "com.android.launcher") return;

        LOGI("Oplus Dock Grid loaded in System Launcher");
        LOGI("Runtime hook is intentionally disabled until the exact ArtMethod layout is validated.");
    }

private:
    zygisk::Api* api_ = nullptr;
    JNIEnv* env_ = nullptr;
};

REGISTER_ZYGISK_MODULE(OplusDockGrid)
