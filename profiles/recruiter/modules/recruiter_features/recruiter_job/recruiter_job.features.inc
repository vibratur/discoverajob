<?php
/**
 * @file
 * recruiter_job.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function recruiter_job_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function recruiter_job_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function recruiter_job_node_info() {
  $items = array(
    'job_per_template' => array(
      'name' => t('Job per template'),
      'base' => 'node_content',
      'description' => t('Create a new job and provide the job details now.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function recruiter_job_default_rules_link() {
  $items = array();
  $items['job_publish'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "publish",
      "link_type" : "token",
      "bundles" : {
        "job_per_file" : "job_per_file",
        "job_per_link" : "job_per_link",
        "job_per_template" : "job_per_template"
      },
      "entity_link" : 1
    },
    "name" : "job_publish",
    "label" : "Job publish",
    "path" : "job_publish",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['job_unpublish'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "unpublish",
      "link_type" : "confirm",
      "bundles" : {
        "job_per_file" : "job_per_file",
        "job_per_link" : "job_per_link",
        "job_per_template" : "job_per_template"
      },
      "entity_link" : 1,
      "confirm_question" : "Are you sure you want to unpublish the selected job?",
      "confirm_description" : "The job will be hidden and needs to be manually published again."
    },
    "name" : "job_unpublish",
    "label" : "Job unpublish",
    "path" : "job_unpublish",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
