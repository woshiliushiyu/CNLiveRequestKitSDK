Pod::Spec.new do |s|

  s.name         = "CNLiveRequestKitSDK"
  s.version      = "1.0.8"
  s.summary      = "LSY-iOS 网络请求基础工具"# 项目简介
  s.homepage     = "https://github.com/woshiliushiyu/CNLiveRequestKitSDK"
  s.source       = { :git => "https://github.com/woshiliushiyu/CNLiveRequestKitSDK.git", :tag => "#{s.version}" }
  s.license      = "MIT"          # 开源证书
  s.author       = { 'woshiliushiyu' => '1010530278@qq.com' }
  s.platform     = :ios, "9.0" #平台及支持的最低版本
  s.frameworks   = "UIKit", "Foundation"#支持的框架

  s.subspec 'CNLiveRequestKitSDK' do |sp|
    sp.vendored_frameworks = 'CNLiveRequestKitSDK.framework'
    sp.dependency 'AFNetworking'
  end

end
