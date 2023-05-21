<launch>
  <param name="my_param" type="string" value="$(find my_package)/config/yaml.yaml" />

  <node name="yaml_pub" type="yaml_pub" output="screen" />

  <node name="yaml_sub" type="yaml_sub" output="screen" />
</launch>
