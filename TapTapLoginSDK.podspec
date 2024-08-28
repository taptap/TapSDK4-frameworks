Pod::Spec.new do |s|
  s.name             = 'TapTapLoginSDK'
  s.version          = '4.3.10'
  s.summary          = '提供 TapTap 登录能力。'

  s.description      = <<-DESC
  提供 TapTap 登录能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'git@github.com:taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapLoginSDK.xcframework"
  s.resources = 'Frameworks/TapTapLoginResource.bundle'
  s.dependency 'TapTapCoreSDK', s.version.to_s
  s.dependency 'Kingfisher', '~> 6.0'
  s.frameworks = 'UIKit',
                 'Foundation',
                 'CoreTelephony',
                 'SystemConfiguration',
                 'AdSupport',
                 'GameController'
  s.library = 'c++'

end
