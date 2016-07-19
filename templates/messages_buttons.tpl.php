<div class="row">
  <a href="#" class="btn btn-primary btn-lg" data-toggle="modal" data-target="#myModal">
    <span class="glyphicon glyphicon-envelope" aria-hidden="true"></span> <?php print t('New message'); ?></a>
  <a href="<?php print base_path() . 'my-messages/update/nojs'; ?>" class="btn btn-default btn-lg use-ajax">
    <span class="glyphicon glyphicon-refresh" aria-hidden="true"></span> <?php print t('Update'); ?></a>
</div>
<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="myModalLabel"><?php print t('New Message'); ?></h4>
      </div>
      <div class="modal-body">
        <?php print render($send_form); ?>
      </div>
    </div>
  </div>
</div>
