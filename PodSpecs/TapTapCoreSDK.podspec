Pod::Spec.new do |s|
  s.name             = 'TapTapCoreSDK'
  s.version          = '4.8.3'
  s.summary          = '是一套专注于解决游戏项目数据需求的分析工具，致力于帮开发者实现低成本、高效率的接入与查询体验。'

  s.description      = <<-DESC
  服务提供的主要功能有：基础 BI、衍生事件、广告投放跟踪、自定义事件分析。
  低门槛接入：接入基础事件非常简单，而这已足够让你获得非常完善的分析和广告投放能力。
  结合 TapTap 生态的数据，为开发者提供全链路的游戏数据分析能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapCoreSDK.xcframework"
  s.dependency 'TapTapGidSDK', s.version.to_s

  s.frameworks = 'UIKit',
                 'Foundation',
                 'CoreTelephony',
                 'SystemConfiguration',
                 'AdSupport',
                 'GameController'
  s.library = 'c++'

end
