Pod::Spec.new do |s|
  s.name             = 'TapTapGidSDK'
  s.version          = '4.7.0-beta.8'
  s.summary          = '提供获取 GID 的功能'

  s.description      = <<-DESC
  提供获取 GID 的功能.
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapBasicToolsSDK.xcframework", "Frameworks/THEMISLite.xcframework", "Frameworks/TapTapNetworkSDK.xcframework", "Frameworks/TapTapGidSDK.xcframework", "Frameworks/tapsdkcorecpp.xcframework"

  s.frameworks = 'UIKit', 'Foundation', 'CoreTelephony', 'SystemConfiguration', 'AdSupport', 'GameController'
    
  s.libraries = ['c++']
  s.xcconfig = {
    'OTHER_LDFLAGS' => '-lz.1'
  }

end
